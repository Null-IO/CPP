#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

int main(int argc, char ** argv) {
	printf("char is %ld bits\n", sizeof(char) * 8);
	printf("short int is %ld bits\n", sizeof(short int) * 8);
	printf("int is %ld bits\n", sizeof(int) * 8);
	printf("long int is %ld bits\n", sizeof(long int) * 8);
	printf("long long int is %ld bits\n", sizeof(long long int) * 8);
	
	printf("\n");
	
	printf("int8_t is %ld bits\n", sizeof(int8_t) * 8);
	printf("int16_t is %ld bits\n", sizeof(int16_t) * 8);
	printf("int32_t is %ld bits\n", sizeof(int32_t) * 8);
	printf("int64_t is %ld bits\n", sizeof(int64_t) * 8);
	
}


