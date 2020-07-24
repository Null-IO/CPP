#include <iostream>
#include <cstdio>
using namespace std;

class int_to_string {
private:
	int i;
public:
	int_to_string(int setter = 1) : i(setter) {};
	operator std::string () const;
	~int_to_string () { i = 1; };
};

int_to_string::operator std::string() const {
	const static int maxsize = 64;
	char ch[maxsize];
	snprintf(ch, maxsize, "%d", i);
	return std::string(ch);
}

int main(int argc, char ** argv) {
	int i; string s = "This shit is integer ";
	cin >> i; 
	int_to_string z(i);
	s += z;
	cout << s;
}


