#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

//Optimized Spinlock
class SpinlockEff {
private:
	atomic_flag flag = ATOMIC_FLAG_INIT;
public:
	void lock() {
		while (flag.test_and_set(memory_order_acquire)); //only test_and_set && clear are synchronized(atomic operations) not global sync, unlike sequential consistency
	}

	void unlock() {
		flag.clear(memory_order_release);
	}
};

SpinlockEff spin;

void workOnResource() {
	spin.lock();
	//Critical code here
	spin.unlock();
}

int main(int argc, char** argv) {
	std::thread t(workOnResource);
	std::thread t2(workOnResource);
	t.join();
	t2.join();
	
	return 0;
}