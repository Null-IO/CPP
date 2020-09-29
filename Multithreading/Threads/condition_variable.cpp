#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex mutex_;
condition_variable condVar;

bool dataReady = false;

void doTheWork() {
	cout << "Processing shared data." << endl;
}

void waitingForWork() {
	cout << "Worker: Waiting for work." << endl;
	unique_lock<mutex> lck(mutex_);
	condVar.wait(lck, [] {return dataReady; }); //waits for the notification to lock the mutex and continue the execution
	doTheWork();
	cout << "Work is done." << endl;
}

void setDataReady() {
	{
		lock_guard<mutex> lck(mutex_);
		dataReady = true;
	}
	cout << "Sender: Data is ready." << endl;
	condVar.notify_one(); //sends notification to 1 waiting thread
}

int main(int argc, char** argv) {
	thread t1(waitingForWork);
	thread t2(setDataReady);

	t1.join(); t2.join();

	return 0;
}