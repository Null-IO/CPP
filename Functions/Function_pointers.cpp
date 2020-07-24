#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int sum(int a, int b) {
	return a + b;
}

int substraction(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

int (*pa[4])(int a, int b) = { sum, substraction, multiply, divide };
int (**pt)(int a, int b) = pa; //or auto pt = pa;
int (*(*pt2)[4])(int a, int b) = &pa; //pointer to the whole array, difference you can't increment this pointer!

int main(int argc, char** argv) {
	for (int i = 0; i < 4; i++) {
		cout << pa[i](69, 3) << endl;
		cout << (*(pt + i))(10, 5) << endl;
	}

	cout << (*pt2)[0](20, 4) << endl;

	return 0;
}
