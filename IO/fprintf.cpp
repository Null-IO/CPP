#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char ** argv) {
	int i = 47;
	long int li = 1234567890;
	const char *s = "This is a string";
	
	FILE *fh = fopen("Test_File.txt", "w");
	fprintf(fh, "i is %d, li is %ld, s is %s\n", i, li, s);
	fclose(fh);
	
	const size_t maxSize = 128;
	char buff[maxSize];
	snprintf(buff, maxSize, "i is %d, li is %ld, s is %s", i, li, s);
	puts(buff);
	
	return 0;
}


