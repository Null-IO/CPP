#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

template<typename T>
T fetch_mult(std::atomic<T>& shared, T mult) { //lock free
	T oldvalue = shared.load();
	while (!shared.compare_exchange_strong(oldvalue, oldvalue * mult));
	return oldvalue;
}

int main(int argc, char** argv) {
	atomic<int> myInt{ 5 };
	cout << myInt << endl;
	fetch_mult(myInt, 5);
	thread t1(fetch_mult<int>, ref(myInt), 6);
	cout << myInt << endl;
	thread t2(fetch_mult<int>, ref(myInt), 2);
	t1.join(); t2.join();
	cout << myInt << endl;
	
	return 0;
}