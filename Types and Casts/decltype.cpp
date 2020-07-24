#include <iostream>
#include <cstdio>
#include <string>
#include <typeinfo>
using namespace std;

template<typename lhsT, typename rhsT>
auto tf(lhsT & lhs, rhsT & rhs) -> decltype(lhs + rhs){ //<-- cool shit!!!
	return lhs + rhs;									 
}

int main(int argc, char ** argv) {
	int i = 47;
	const char *cstr = "this is a c-string";
	string strobj("this is a cpp-string");
	
	auto x = string("this is a cpp-string X");
	decltype(x) y; //x is string so decltype makes y string too!!!
	
	cout << "type of i is " << typeid(i).name() << endl;
	cout << "type of cstr is " << typeid(cstr).name() << endl;
	cout << "type of i is " << typeid(strobj).name() << endl;
	cout << "type of i is " << typeid(x).name() << endl;
	cout << "type of i is " << typeid(y).name() << endl;
	
	auto z = tf(strobj, cstr);
	cout << "z is " << z << endl;
	cout << "type of z is " << typeid(z).name();
}


