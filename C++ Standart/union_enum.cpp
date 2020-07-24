//simple union and enum example, P.S, U can do it(union can hold only 1 value!!!)
//+ || - and shit like that ar mosula on enum!
#include <iostream>
#include <cstdio>
using namespace std;

enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};

spectrum operator + (spectrum t1, spectrum t2) {
	int a = t1, b = t2;
	return spectrum(a + b);
}

struct widget {
	int wType;
	
	union {
		long id_num;
		char id_char[20];
	};
};

int main(int argc, char ** argv) {
	widget z;
	spectrum sp = blue + violet;
	cin >> z.wType;
	if(z.wType == 1) {
		cin >> z.id_num;
		cout << z.id_num;
	} else {
		cin >> z.id_char;
		cout << z.id_char;
	}
	cout << endl << "Enums:" << endl;
	cout << red << " " << orange << " " << yellow << " " << green << " " << blue << " " << violet << " " << indigo << " " << ultraviolet << endl;
	cout << "Enum type variable:" << endl;
	cout << sp;
	
}


