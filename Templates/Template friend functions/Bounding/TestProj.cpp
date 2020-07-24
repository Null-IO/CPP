//Bounding Template Friend Functions(Best approach i think)
//Doesn't work with .cpp file
#include "Header.h"
#include <iostream>
using std::cout; using std::endl;

int main() {
	counts<int>();
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.5);
	report(hfi1); // generate report(HasFriendT<int> &)
	report(hfi2); // generate report(HasFriendT<int> &)
	report(hfdb); // generate report(HasFriendT<double> &)
	cout << "counts<int>() output:\n";
	counts<int>();
	cout << "counts<double>() output:\n";
	counts<double>();

	return 0;
}