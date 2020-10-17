#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
using namespace std;

atomic<int> atom{0};
int shared{0};
using namespace chrono_literals;

void writeShared() {
	shared = 2011;
	atom.store(2, memory_order::memory_order_release);
}

void readShared() {
	while (!(atom.fetch_sub(1, memory_order::memory_order_acquire) > 0)) //The release sequence from .store is extended to second call to .fetch_sub and data race on "shared" doesn't occur
		this_thread::sleep_for(100ms);
	
	std::cout << "shared: " << shared << std::endl;
}

int main(int argc, char** argv) {
	thread t1(writeShared);
	thread t2(readShared);
	thread t3(readShared);

	t1.join(); t2.join(); t3.join();
	cout << atom << endl;

	return 0;
}