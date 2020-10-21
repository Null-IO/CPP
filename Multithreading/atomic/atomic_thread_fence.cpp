#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

/*
1. The acquire and release fences prevent the reordering of the atomic and non-atomic operations
across the fences.

2. The consumer thread t2 is waiting in the while (!(p2= ptr.load(std::memory_order_-
relaxed))) loop, until the pointer ptr.store(p,std::memory_order_relaxed) is set in the
producer thread t1.

3. The release fence synchronizes-with the acquire fence.

4. In the end, all effects of relaxed or non-atomic operations that happen-before the release fence
are visible after the acquire fence.
*/

atomic<string*> ptr;
int Data;
atomic<int> atoData;

void producer() {
	string* p = new string("C++20");
	Data = 2011;
	atoData.store(2014, memory_order_relaxed); //_release in case of syncing with atomics
	atomic_thread_fence(memory_order_release);
	ptr.store(p, memory_order_relaxed);
}

void consumer() {
	string* p2;
	while (!(p2 = ptr.load(memory_order_relaxed)));  //_acquire in case of syncing with atomics
	atomic_thread_fence(memory_order_acquire);
	cout << "*p2: " << *p2 << endl;
	cout << "data: " << Data << endl;
	cout << "atoData: " << atoData.load(memory_order_relaxed) << endl;
}

int main(int argc, char** argv) {
	thread t1(producer);
	thread t2(consumer);

	t1.join(); t2.join();

	return 0;
}