#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std;

int main(int argc, char** argv) {
	int res = 0;
	thread t([&] { res = 2000 + 11; });
	t.join();

	cout << "res: " << res << endl;

	auto fut = async([] { return 2000 + 11; }); //"Promise" puts data to communcation channel
	cout << "fut.get(): " << fut.get() << endl; //"Future" retrieves it

	cout << endl;
	auto begin = chrono::system_clock::now();
	
	auto asyncLazy = async(launch::deferred, [] { return chrono::system_clock::now(); }); //calculates result when .get() is called
	auto asyncEager = async(launch::async, [] { return chrono::system_clock::now(); }); //calculates result immediately

	this_thread::sleep_for(chrono::seconds(1));

	auto lazyStart = asyncLazy.get() - begin;
	auto eagerStart = asyncEager.get() - begin;

	auto lazyDuration = chrono::duration<double>(lazyStart).count();
	auto eagerDuration = chrono::duration<double>(eagerStart).count();
	
	cout.setf(ios_base::floatfield, ios_base::fixed);
	std::cout << "asyncLazy evaluated after : " << lazyDuration << " seconds." << std::endl;
	std::cout << "asyncEager evaluated after: " << eagerDuration << " seconds." << std::endl;

	return 0;
}