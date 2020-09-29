#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

struct criticalData {
	mutex mut;
};

void deadlock(criticalData& a, criticalData& b) {
	unique_lock<mutex> guard1(a.mut, defer_lock); //std::defer_lock -> doesn't locks mutex automatically
	cout << "Thread: " << this_thread::get_id() << " first mutex" << endl;
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	
	unique_lock<mutex> guard2(b.mut, defer_lock);
	std::cout << "Thread: " << this_thread::get_id() << " get the second mutex" << std::endl;

	cout << "Thread: " << this_thread::get_id() << " get both mutex" << endl;
	lock(guard1, guard2); //prevents deadlock
	//critical code here
	
	//Also would work here --> scoped_lock(a.mut, b.mut)
}

int main(int argc, char** argv) {
	criticalData c1, c2;

	thread t1([&] { deadlock(c1, c2); });
	thread t2([&] { deadlock(c2, c1); });

	t1.join();
	t2.join();

	return 0;
}