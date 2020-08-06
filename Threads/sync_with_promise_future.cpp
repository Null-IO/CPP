#include <iostream>
#include <future>
#include <utility>
using namespace std;

void doTheWork() {
	cout << "Processing shared data." << endl;
}

void waitingForWork(future<void>&& fut) {
	cout << "Worker: Waiting for work." << endl;
	fut.wait();
	doTheWork();
	cout << "Work done." << endl;
}

void setDataReady(promise<void>&& prom) {
	cout << "Sender: Data is ready." << endl;
	prom.set_value(); //communicates using promise's return value
}

int main(int argc, char** argv) {
	promise<void> sendReady;
	auto fut = sendReady.get_future();

	thread t1(waitingForWork, move(fut));
	thread t2(setDataReady, move(sendReady));

	t1.join(); t2.join();

	return 0;
}