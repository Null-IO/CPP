#include <iostream>
#include <cstdio>
using namespace std;

class Write_Me {
public:
	int a, b;
	char ch;
	string s;
	Write_Me(int ca, int cb, char cch, string cs) : a(ca), b(cb), ch(cch), s(cs) {};
	~Write_Me() {};
};

int main(int argc, char ** argv) {
	int a, b; char ch; string s;
	cin >> a >> b >> ch >> s;
	Write_Me wm(a, b, ch, s);
	
	
	FILE *fw = fopen(s.c_str(), "wb");
	fwrite(&wm, sizeof(class Write_Me), 1, fw);
	fclose(fw);
	
	FILE *fr = fopen(s.c_str(), "rb");
	size_t t;
	while(t = fread(&wm, sizeof(class Write_Me), 1, fr));
		printf("%d, %d, %c, %s", wm.a, wm.b, wm.ch, wm.s.c_str());
	
	fclose(fr);
}


