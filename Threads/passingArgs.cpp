#include <iostream>
#include <thread>
#include <memory>
#include <ctime>
using namespace std;

class foo {
private:
	int& i;
public:
	explicit foo(int& _i) : i(_i) {};
	inline void processData(const int& data) const { i = data; }
	friend inline ostream& operator << (ostream& os, const foo& f) { os << f.i; return os; };
};

void processFoo(unique_ptr<foo> obj) {
	srand(time(NULL));

	for (size_t i = 10; i <= 20; i++)
		obj.get()->processData(rand() % i);

	cout << "Final data: " << *obj.get() << endl;
}

int main(int argc, char** argv) {
	srand(time(NULL));
	int i = rand() % 50;
	
	unique_ptr<foo> z(new foo(i));
	cout << "Initial data: " << *z.get() << endl;
	thread th1(processFoo, move(z)); //move() transfers ownership
	th1.join();

	return 0;
}