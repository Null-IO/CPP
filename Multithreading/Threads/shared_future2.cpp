#include <iostream>
#include <thread>
#include <future>
#include <utility>
#include <cctype>
#include <ctime>
using namespace std;

mutex cMtx;

class Obj {
public:
	double a = 0; double b = INT_MAX; double c = 0;

	explicit Obj(double a_, double b_) : a(a_), b(b_), c(a_ / b_) {};
	explicit Obj() = default;
};

struct Div {
	void operator() (promise<Obj>&& objPromise, double a, double b) {
		Obj obj(a, b);
		objPromise.set_value(obj);
	}
};

struct Requestor {
	void operator() (shared_future<Obj> shaFut) {
		lock_guard<mutex> lck(cMtx);
		Obj result = shaFut.get();
		cout << "threadId(" << std::this_thread::get_id() << "): " << result.a << " / " << result.b << " = " << result.c << endl;
	}
};

int main(int argc, char** argv) {
	cout.setf(ios_base::boolalpha);
	
	srand(time(NULL));
	promise<Obj> objPromise;
	future<Obj> Ftr = objPromise.get_future();
	cout << Ftr.valid() << endl;

	Div div;
	thread divThread(div, move(objPromise), (rand() % 100), (rand() % 100));

	cout << Ftr.valid() << endl;
	shared_future<Obj> sFtr = Ftr.share(); //Another way to create shared_future
	cout << Ftr.valid() << endl; //false, cause it is currently associated with a shared state.
	
	vector<thread> ths;
	Requestor req;

	for (size_t i = 0; i < 5; i++)
		ths.emplace_back(req, sFtr);
	
	divThread.join();
	
	for (auto& it : ths)
		it.join();

	return 0;
}