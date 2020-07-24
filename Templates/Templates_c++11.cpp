#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... Args) {
	cout << firstArg << endl;
	print(Args...);
}

template<typename T>
using Vec = vector<T>; //typedef using templates

int main(int argc, char ** argv) {
	Vec<int> gio= {6, 5, 8, 0, 5};
	auto gio_it = gio.begin();
	
	for(;gio_it < gio.end(); ++gio_it)
		cout << *gio_it << " ";
	
	cout << endl;
	print(7.5, "hello", bitset<16>(377), 42);
}


