#include <iostream>
#include <cstdio>
using namespace std;

struct character {
	bool Bald : 1;
	bool Cool : 1;	//<-- number of bits this values will take in structure!!!
	bool has_car : 1;
	unsigned int Number_of_children : 2;
};

int main(int argc, char ** argv) {
	character zaza;
	zaza.Bald = 1;
	zaza.Cool = 1;
	zaza.has_car = 1;
	zaza.Number_of_children = 2;
	
	printf("%ld ", sizeof(zaza) * 8);
}


