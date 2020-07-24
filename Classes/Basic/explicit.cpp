#include <iostream>
#include <cstdio>
using namespace std;

const size_t _maxsize = 1024;

class strsize {
private:
	size_t _size = 0;
public:
	explicit strsize(const int);
	explicit strsize(const char *);
	size_t size() const;
};

strsize::strsize(const int n) {
	_size = (n <= _maxsize) ? n : 0;
}

strsize::strsize(const char * s) {
	for(size_t i = 0; i < _maxsize; i++) {
		if(s[i] == 0) {
			_size = i;
			return;
		}
	}
	_size = 0;
}

size_t strsize::size() const {
	return _size;
}

void func(const strsize & s) {
	printf("size is %ld\n", s.size());
}

int main(int argc, char ** argv) {
	strsize s(1000);
	printf("size is %ld\n", s.size());
	func(strsize("hello and my name is zuka and trying to study c++ on my own"));
	return 0;
}


