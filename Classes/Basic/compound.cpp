#include <iostream>
#include <cstdio>
using namespace std;

class num {
private:
	int value;
public:
	num(int constVal) : value(constVal) {}
	int get_value () const { return value; }
	void set_value(int val) {value = val;}
	num & operator += (const num & n);
};

num & num::operator += (const num & n) {
	value += n.value;
	return *this;
}

int main(int argc, char ** argv) {
	num n1(5);
	num n2(10);
	
	n1 += n2;
	printf("%d ", n1);
}


