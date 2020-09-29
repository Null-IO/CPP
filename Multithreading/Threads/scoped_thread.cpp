#include <iostream>
#include <thread>
#include <ctime>
using namespace std;

class scoped_thread { //takes ownership of a thread, which is passed directly with a std::move()
private:
	thread t;
public:
	explicit scoped_thread(thread _t) : t(move(_t)) {
		if (!t.joinable())
			throw std::logic_error("No thread");
	}
	scoped_thread(const scoped_thread& t) = delete;
	scoped_thread& operator = (const scoped_thread& t) = delete;
	~scoped_thread() { t.join(); } //automatically joins the thread
};

void do_something(int i) {
	cout << i << endl;
}

struct func {
	int& i;
	func(int& i_) :i(i_) {}
	void operator()() {
		srand(time(NULL));
		for (size_t j = 1; j <= 25; ++j)
			do_something(rand() % i);
	}
};

int main(int argc, char** argv) {
	int z = 47;
	scoped_thread st{ thread(func(z)) };

	return 0;
}