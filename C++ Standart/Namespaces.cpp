#include <iostream>
#include <cstdio>
#include <string>

namespace zString {

const std::string prefix = "zString";

class string {
private:
	std::string s = "";
	string();
public:
	string (const std::string & s);
	const char * c_str();
	operator const std::string & ();
	~string();
	
};

string::string (const std::string & s) : s(prefix + s) {};

const char * string::c_str() {return s.c_str();}

string::operator const std::string & () { return s; }

string::~string() {};

};

using namespace zString;

int main(int argc, char ** argv) {
	std::string a;
	std::cin >> a;
	string s(a);
	printf("%s", s.c_str());
}


