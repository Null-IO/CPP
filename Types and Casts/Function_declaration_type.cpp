//specifies function return type on the fly
#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) {
	string tst;
	
	if(typeid(x + y) == typeid(tst))
		return x + ' ' + y;
	
	return x + y;
}

int main(int argc, char ** argv) {
	string s1 = "Zuka", s2 = "Gio";
	
	cout << add(s1, s2) << endl;
	cout << add(96, 6009) << endl;
	cout << add(5.51, 3.36) << endl;
	cout << add('Z', 'G') << endl;
	
}


