#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

/*
access to the shared variable mySharedWork is synchronised
using the condition variable condVar or the atomic dataReady. This holds, although mySharedWork
itself is not protected by a lock or is an atomic.
*/
vector<int> mySharedWork;
atomic<bool> dataReady(false); 

void waitForWork() {
	cout << "Waiting... " << endl;
	while (!dataReady.load())
		this_thread::sleep_for(chrono::milliseconds(5));
	
	mySharedWork[1] = 2;
	cout << "Work done " << endl;
}

void setDataReady() {
	mySharedWork = { 1, 0, 3 };
	dataReady = true;
	cout << "Data prepared" << endl;
}

int main(int argc, char** argv) {
	std::thread t1(waitForWork);
	std::thread t2(setDataReady);
	t1.join();
	t2.join();
	
	for (auto& v : mySharedWork)
		std::cout << v << " ";

	return 0;
}