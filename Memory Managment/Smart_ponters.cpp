#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main() {
	shared_ptr<string> SR[4] = {
		unique_ptr<string>(new string("Win94")), //Better than auto_ptr, Can use delete[] and if ptr is rvalue, unique_ptr<Type>(rvalue)-> is valid.(see below)
		unique_ptr<string>(new string("Kar98k")), //shared_ptr must be used on pointers, that point to same memory location.
		unique_ptr<string>(new string("M24")),
		unique_ptr<string>(new string("AWM"))
	};
	/*
	unique_ptr<string> pu1(new string "Hi ho!");
	unique_ptr<string> pu2;
	pu2 = pu1; //#1 not allowed
	unique_ptr<string> pu3;
	pu3 = unique_ptr<string>(new string "Yo!"); //#2 allowed
	
	OR USING std::move
	
	unique_ptr<string> ps1, ps2;
	ps1 = demo("Uniquely special");
	ps2 = move(ps1); // enable assignment
	ps1 = demo(" and more");
	*/
	shared_ptr<string> bSR = SR[3];
	
	cout << "Sniper Rifles:" << endl;
	for (int i = 0; i < 4; i++)
		cout << *SR[i] << endl;
	
	cout << "Best Sniper Rifle: " << *bSR << endl;

	return 0;
}