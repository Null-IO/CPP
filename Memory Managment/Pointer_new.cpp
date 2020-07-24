#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char ** argv) {
	int s = 69, w = 420;
	int* sp = &s; int* sw = &w; int* placeholder = nullptr;
	puts("Before swapping");
	cout << *sp << " " << *sw << endl;
	
	placeholder = sp; sp = &w; sw = placeholder;
	
	puts("After swapping");
	cout << *sp << " " << *sw << endl << endl;
	
//Optimizing way to declare variable with pointer in order to use memory more effectively.
//You can apply delete only on objects, that were creating by new!!! "delete" doesn't delete the pointer itself you can reuse same pointer with new!!!
//using new is good when declaring large objects
	
	string* vp = new string;
	int* i = new int;
	*vp = "I am a String bitch";
	cout << *vp << endl;
	*i = vp->find("String");
	cout << *i << endl;
	delete vp, i;
	vp = new string;
	*vp = "Here i am again bitch";
	cout << *vp;
	delete vp;
	
	cout << endl << endl;
	cout << "Sorry for swearing above here is the array for you" << endl;
	
	int* psome = new int[10];
	for(int i = 0; i < 10; i++)
		psome[i] = i;
	
	for(int i = 0; i < 10; i++)
		cout << psome[i] << " ";
	
	delete [] psome;
	
}


