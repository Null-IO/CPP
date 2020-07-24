#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdint>
using namespace std;

const size_t slen = 125;

struct s1 {
	uint8_t num;
	uint8_t len;
	char s[slen + 1];
};

int main(int argc, char ** argv) {
	const char *fn = "testBinary";
	const char *str = "This is a literal C-string";
	
	printf("Writing to file\n");
	FILE *fw = fopen(fn, "wb");
	
	struct s1 buf1;
	for(int i = 0; i < 5; i++) {
		buf1.num = i;
		buf1.len = strlen(str);
		
		if(buf1.len > slen) 
			buf1.len = slen;
		
		strncpy(buf1.s, str, slen);
		
		if(buf1.len == slen)
			buf1.s[buf1.len] = 0;
			
		fwrite(&buf1, sizeof(struct s1), 1, fw);
		
	}
	fclose(fw);
	printf("Done writing\n");
	
	printf("Reading the file\n");
	
	FILE *fr = fopen(fn, "rb");
	struct s1 buf2;
	size_t rc;
	while( (rc = fread(&buf2, sizeof(struct s1), 1, fr)) ) {
		printf("a : %d, b : %d, s : %s\n", buf2.num, buf2.len, buf2.s);
	}
	
	fclose(fr);
	remove(fn);
	
	printf("Done");
	
	return 0;
}


