#include <iostream>
#include <cstdio>
#include <cerrno>
#include <cstring>
using namespace std;

int main(int argc, char ** argv) {
	printf("Errno is: %d\n", errno);
	remove("Foo.bar");
	printf("Errno is: %d\n", errno);
	perror("Couldn't erase the file");
	printf("Error Message is: %s\n", strerror(errno));
	return 0;
}


