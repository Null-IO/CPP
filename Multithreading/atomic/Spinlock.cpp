#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
using namespace std;

//Elementary lock such as mutex, but fully utilize core 1 of CPU and is only efficient if thread gets lock for a short period of time
class Spinlock {
	std::atomic_flag flag = ATOMIC_FLAG_INIT; //Set flag to false
public:
	void lock() {
		while (flag.test_and_set()); //If the flag is false, set it to true
	}
	void unlock() {
		flag.clear(); //Set the flag back to clear
	}
};

Spinlock spin;

void workOnResource() {
	spin.lock();
	this_thread::sleep_for(chrono::milliseconds(2000));
	spin.unlock();
}

int main(int argc, char** argv) {
	thread t1(workOnResource);
	thread t2(workOnResource);

	t1.join(); t2.join();

	return 0;
}