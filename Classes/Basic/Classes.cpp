#include <iostream>
#include <cstdio>
using namespace std;

class Class1 {
private:
	int i;
	int foo() const {return i * 69;}
public:
	void setValue(const int value);
	int getValue() const;
	int getFooVal() const;
};

void Class1::setValue(const int value) {
	i = value;
}

int Class1::getValue() const {
	return i;
}

int Class1::getFooVal() const {
	return foo();
}

int main(int argc, char ** argv) {
	int i = 47;
	Class1 Z;
	
	Z.setValue(i);
	printf("Value is %d\n", Z.getValue());
	printf("Foo is %d\n", Z.getFooVal());
}


