#include <iostream>
#include <cstdio>
#include <typeinfo>
using namespace std;

struct A{ int x; };
struct B{ int x; };

struct A a1;
struct A a2;
struct B b1;
struct B b2;

int main(int argc, char ** argv) {
	if(typeid(A) == typeid(a1))
		puts("Same");
	
	if(typeid(A) != typeid(b1))
		puts("Different");
	
	printf("type is %s ", typeid(b1).name());
}


