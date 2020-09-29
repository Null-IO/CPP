#include <iostream>
#include <future>
#include <exception>
#include <utility>
#include <thread>
#include <string>
using namespace std;

struct Div {
	void operator() (promise<int>&& intPromise, int a, int b) {
		try {
			if (b == 0) {
				string errMsg = string("Illegal division by zero: ") + to_string(a) + " / " + to_string(b);
				throw runtime_error(errMsg);
			}
			intPromise.set_value(a / b);
		
		}
		catch (...) {
			intPromise.set_exception(current_exception()); //wraps caught exception
		}
	}
};

void executeDivision(int nom, int denom) {
	promise<int> divPromise;
	future<int> divResult = divPromise.get_future();

	Div div;
	thread divThread(div, move(divPromise), nom, denom);

	try {
		cout << nom << " / " << denom << " = " << divResult.get() << endl; //if exception has occurred, exception is rethrown
	
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}
	divThread.join();
}

int main(int argc, char** argv) {
	executeDivision(20, 0);
	executeDivision(20, 10);

	return 0;
}