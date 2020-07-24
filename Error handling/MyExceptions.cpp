#include <iostream>
#include <cstdio>
#include <exception>
using namespace std;

class E : public exception {
private:	
	const char *msg = nullptr;
	E (){};
public:
	E (const char *s) throw() : msg(s) {}
	const char *what() const throw() { return msg; }
};

class Z {
private:
	int a;
	Z (){};
public:
	Z (int set_a);
	inline int get_a() const { return a; };
	~Z();
};

Z::Z(int set_a = 32) : a(set_a) {
	if(set_a < 32)
		throw E("a is less than 32");
};

Z operator + (const Z & lhs, const Z & rhs) {
	return Z(lhs.get_a() + rhs.get_a());
};

std::ostream & operator << (std::ostream & o, const Z & r) {
    return o << r.get_a();
}

Z::~Z() {
	a = 32;
}

int main(int argc, char ** argv) {
	try {
		int a, b;
		cin >> a >> b;
		Z obj1(a); Z obj2(b);
		
		cout << obj1 + obj2;
	
	} catch(exception & e) {
		cerr << e.what();
	}
}


