#include <iostream>
#include <cstdio>
using namespace std;

class Multby {
private:
	int mult = 1;
	Multby();
public:
	Multby(int n) : mult(n) {}
	int operator () (int n) const {return mult * n;}
};

int main(int argc, char ** argv) {
	const Multby times4(4);
	const Multby times8(8);
	const Multby times16(16);
	
	printf("times4(5) is %d\n", times4(5));
	printf("times4(25) is %d\n", times4(25));
	printf("times8(5) is %d\n", times8(5));
	printf("times8(25) is %d\n", times8(25));
	printf("times16(5) is %d\n", times16(5));
	printf("times16(25) is %d\n", times16(25));
	
}


