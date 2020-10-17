#include <iostream>
#include <atomic>
#include <thread>
#include <string>
using namespace std;

atomic<string*> ptr;
int Data = 0;
atomic<int> atoData;

void producer() {
	string* p = new string("C++20");
	Data = 2011;
	atoData.store(2014, memory_order::memory_order_relaxed);
	ptr.store(p, memory_order::memory_order_release);
}

void consumer() {
	/*
	Deals with data dependencies only, therefore, we may have data race on int Data, because it is not being
	synchronized as with release - acquire semantic. May be faster on certain systems, than release - acquire semantic 
	*/
	string* p2;
	while (!(p2 = ptr.load(memory_order_consume))); //Mapped to std::memory_order_acquire in newer compilers
	cout << "*p2: " << *p2 << endl;
	cout << "Data: " << Data << endl;
	cout << "atoData: " << atoData.load(memory_order_relaxed) << endl;
}

int main(int argc, char** argv) {
	thread t1(producer);
	thread t2(consumer);
	t1.join(); t2.join();

	return 0;
}