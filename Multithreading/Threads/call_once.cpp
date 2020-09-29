#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Singleton {
private:
	static once_flag initInstanceFlag;
	static Singleton* instance;
	Singleton() = default;
	~Singleton() = default;
public:
	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;

	static void initSingleton() {
		instance = new Singleton();
	}

	static Singleton* getInstance() {
		call_once(initInstanceFlag, Singleton::initSingleton);
		return instance;
	}
};

Singleton* Singleton::instance = nullptr;
once_flag Singleton::initInstanceFlag;

class MeyersSingleton {
private:
	MeyersSingleton() = default;
	~MeyersSingleton() = default;
	MeyersSingleton(const Singleton&) = delete;
	MeyersSingleton& operator = (const Singleton&) = delete;
public:
	static MeyersSingleton& getInstance() {
		static MeyersSingleton instance;
		return instance;
	}
};

once_flag onceFlag;

void do_once(bool exc = false) {
	call_once(onceFlag, [&]() { if (exc) throw logic_error("Error"); std::cout << "Only once." << std::endl; });
}

void do_once2(bool exc = false) {
	call_once(onceFlag, [&]() { if (exc) throw logic_error("Error"); std::cout << "Only once2." << std::endl; });
}

int main(int argc, char** argv) {
	//call_once(onceFlag, /.../ }); call_once will execute function only 1 time. functions registered with once_flag will be invoked only once
	//if invoked function throws an exception, the second registered one will be invoked
	thread t1(do_once, false); //true will invoke do_once2
	thread t2(do_once, false);

	thread t3(do_once2, false);
	thread t4(do_once2, false);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << "Singleton::getInstance(): " << Singleton::getInstance() << endl; //only one instance of a Singleton is created
	cout << "Singleton::getInstance(): " << Singleton::getInstance() << endl;
	cout << &MeyersSingleton::getInstance() << endl; //analog to Singleton
	cout << &MeyersSingleton::getInstance() << endl;

	return 0;
}