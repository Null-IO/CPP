#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char ** argv) {
	const static int MaxSize = 256;
	char buff[MaxSize];
	fputs("Input: ", stdout);
	fflush(stdout);
	fgets(buff, MaxSize, stdin);
	fputs(buff, stdout);
}


