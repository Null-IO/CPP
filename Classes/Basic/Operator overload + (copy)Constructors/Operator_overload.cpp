#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class Z1 {
private:
	int a = 0, b = 1;
public:
	Z1(int Ca, int Cb);
	inline int getA() const { return a; };
	inline int getB() const { return b; };
	Z1 operator + (const Z1 & rhs) const;
	Z1 & operator = (const Z1 & rhs);
	~Z1();
	
};

Z1::Z1(int Ca = 0, int Cb = 1) : a(Ca), b(Cb) {};

Z1 Z1::operator + (const Z1 & rhs) const {
	return Z1((a + b), (rhs.a + rhs.b));
}

Z1 & Z1::operator = (const Z1 & rhs) {
	if(this != &rhs) {
		a = rhs.getA();
		b = rhs.getB();
	}
	return *this;
}

std::ostream & operator << (std::ostream & o, const Z1 & r) {
    return o << r.getA() << '+' << r.getB();
}

Z1::~Z1() {
	a = 0;
	b = 1;
};

int main(int argc, char ** argv) {
	Z1 a = 1;
	Z1 b (3, 4);
	Z1 c = b;
	Z1 d;
	d = c;
	Z1 &e = d;
	d = e;
	
	cout << a + b + c + d + e << endl;
	
	d = c = b = a;
	
	cout << a + b + c + d + e << endl;
	
}


