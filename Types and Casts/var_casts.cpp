#include <iostream>
using std::cout;
using std::endl;

struct dat { short a; short b; };

void change(const int* pt, int n) {
	int* pc = nullptr;
	pc = const_cast<int*>(pt); //Removes const from arguments only not original variable itself. Types must be the same!

	*pc += n;
}

int main(int argc, char** argv) {
	int pop1 = 38383;
	const int pop2 = 2000;
	long long d = 0;
	long value = 0xA225B118;
	d = static_cast<long long>(pop1);
	dat* pd = reinterpret_cast<dat*>(&value); //converts any pointer type to any other pointer type, even of unrelated classes(risky)

	cout << std::hex << "a: " << pd->a << " b: " << pd->b << endl;
	cout << std::dec << "d: " << d << ", " << "d's type: " << typeid(d).name() << endl;
	cout << "pop1: " << pop1 << endl << "pop2: " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1: " << pop1 << endl << "pop2: " << pop2 << endl;

	return 0;
}