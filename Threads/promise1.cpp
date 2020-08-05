#include <iostream>
#include <thread>
#include <future>
#include <utility>
using namespace std;

void product(promise<int>&& intPromise, int a, int b) {
	intPromise.set_value(a * b); //puts data manually into communication channel
}

struct Div {
	void operator() (promise<int>&& intPromise, int a, int b) const {
		intPromise.set_value(a / b);
	}
};

int main(int argc, char** argv) {
	int a = 20, b = 10;

	//define the promises
	promise<int> prodPromise;
	promise<int> divPromise;

	//get the futures
	future<int> prodResult = prodPromise.get_future();
	future<int> divResult = divPromise.get_future();

	//calculate the result in a separate thread
	thread prodThread(product, move(prodPromise), a, b);
	Div div;
	thread divThread(div, move(divPromise), a, b);

	cout << "20*10 = " << prodResult.get() << endl;
	cout << "20/10 = " << divResult.get() << endl;

	prodThread.join();
	divThread.join();

	return 0;
}