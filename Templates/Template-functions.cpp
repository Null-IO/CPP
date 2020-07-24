#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

template <typename T> T maxOf(T a, T b) {
	return (a > b ? a : b);
}

int main(int argc, char ** argv) {
	printf("%d\n" ,maxOf<int>(69, 96));
	printf("%s\n", maxOf<const char *>("Zuka", "Gio")); //char* is a pointer to c string array, it point to characters!!!
	printf("%s\n", maxOf<string>("Zuka", "Gio").c_str()); //c++ string is easier to use somesimes but need c_str() with printf!!!
}


