#include <iostream>
#include <cstdio>
using namespace std;

int &f(int &i) {
	++i;
	return i;	//<-- modifies i!
}

const int &fconst(const int &x) {
	static int y = x;
	++y;				//<-- doesn't modifies i!
	return y;
}

int main(int argc, char ** argv) {
	int i = 5;
	printf("Value is %d\n", i);
	printf("Value is %d\n", fconst(i));
	printf("Value is %d\n", i);
}


