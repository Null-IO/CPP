#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex coutMutex;

thread_local string s("Hello from ");
thread_local auto id = this_thread::get_id();

void first() {
	s += "first, ";
}

void second() {
	s += "second, ";
}

void third() {
	s += "third.";
}

void addThreadLocal(const string& s2) {
	s += s2 + " ";
	first(); second(); third();

	//Protecting std::cout for cleaner output
	lock_guard<mutex> guard(coutMutex);
	cout << s << " with ID: " << id << endl;
	cout << "&s: " << &s << endl;
	cout << endl;
}

int main(int argc, char** argv) {
	thread t1(addThreadLocal, "t1");
	thread t2(addThreadLocal, "t2");
	thread t3(addThreadLocal, "t3");
	thread t4(addThreadLocal, "t4");

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}