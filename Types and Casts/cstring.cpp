#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char ** argv) {
	char cstring[] = "String" "String" "String";
	printf("%s\n", cstring);
	
	for(unsigned int i = 0; cstring[i]; i++)
		printf("%01d: %c\n", i, cstring[i]);
		//after %0 literal means how many 0 you want to put
}


