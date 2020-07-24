#include <iostream>
#include <cstdio>
using namespace std;

const int maxString = 1024;

int main(int argc, char ** argv) {
	const char *fn = "Test.txt";
	string str;
	cin >> str;
	str = str + "\n";
	
	printf("writing to file...\n");
	FILE *fw = fopen(fn, "w");
	for(int i = 0; i < 3; i++)
		fputs(str.c_str(), fw);
	
	fclose(fw);
	printf("Done writing\n");
	
	printf("Reading the file...\n");
	char buf[maxString];
	FILE *fr = fopen(fn, "r");
	
	while(fgets(buf, maxString, fr))
		fputs(buf, stdout);
	
	fclose(fr);
	
	printf("Done reading");
}


