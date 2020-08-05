#include <iostream>
#include <thread>
#include <future>
#include <utility>
using namespace std;

mutex cMtx;

struct Div {
	void operator() (promise<int>&& intPromise, int a, int b) {
		intPromise.set_value(a / b); //puts value into channel
	}
};

struct Requestor {
	void operator() (shared_future<int> shaFut) { //shared_future can be copied in contrast to future
		lock_guard<mutex> mtx(cMtx);
		cout << "threadId(" << std::this_thread::get_id() << "): ";
		std::cout << "20/10= " << shaFut.get() << std::endl;
	}
};

int main(int argc, char** argv) {
	//shared_future can request .get() as many times as needed
	promise<int> divPromise;
	shared_future<int> divResult = divPromise.get_future(); //future must be prepared before use
	Div div;
	thread divThread(div, move(divPromise), 20, 10);

	Requestor req;
	thread sharedThread1(req, divResult);
	thread sharedThread2(req, divResult);
	thread sharedThread3(req, divResult);
	thread sharedThread4(req, divResult);
	thread sharedThread5(req, divResult);

	divThread.join();

	sharedThread1.join();
	sharedThread2.join();
	sharedThread3.join();
	sharedThread4.join();
	sharedThread5.join();

	return 0;
}