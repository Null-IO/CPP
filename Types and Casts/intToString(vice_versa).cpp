#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <typeinfo>
using namespace std;

int main(int argc, char** argv) {
	cout << "Input stream to convert to string and vice versa: ";
	int i; cin >> i;

	ostringstream outstr;
	outstr << i;
	string result = outstr.str() + "I";
	cout << result << " Type is " << typeid(result).name() << endl;

	int k = 0;
	istringstream instr(result);
	instr >> k;
	cout << ++k << " Type is " << typeid(k).name() << endl;

	return 0;
}