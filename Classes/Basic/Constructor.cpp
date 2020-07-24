#include <iostream>
#include <cstdio>
using namespace std;

class ClassConstr {
private:
	int ia = 0;
public:
	ClassConstr();
	ClassConstr(const int & i);
	ClassConstr(const ClassConstr & a);
	ClassConstr & operator = (const ClassConstr & o);
	
	void setValue(const int val);
	int getValue() const;
	
	~ClassConstr();
	
};

ClassConstr::ClassConstr(const int & i) : ia(i){
	
}

ClassConstr::ClassConstr(const ClassConstr & a) {
	ia = a.ia;
	printf("Clone!\n");
}

ClassConstr & ClassConstr :: operator = (const ClassConstr & o) {
	if(this != &o)
		ia = o.ia;
	
	return *this;
	
}

void ClassConstr::setValue(const int val) {
	ia = val;
}

int ClassConstr::getValue() const {
	return ia;
}

ClassConstr::~ClassConstr() {
	
}

int main(int argc, char ** argv) {
	int z;
	cin >> z;
	ClassConstr z0(5);
	const ClassConstr z1(z);
	const ClassConstr z2 = z1;
	const ClassConstr z3 = z0;
	
	printf("Value of z0 is %d. Value of z1 is %d. Value of the z2 is %d. The value of z3 is %d ", z0.getValue(), z1.getValue(), z2.getValue(), z3.getValue());
}


