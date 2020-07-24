#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
	ostream_iterator<int, char> out_iter(cout, " "); //int -> type to be written; char -> stream handles(char for ostream); output stream
	//being used; " " seperator.
	for (int i = 0; i < 5; i++)
		*out_iter++ = i * i; //i.e cout << i << " "; send i and then " ".
	cout << endl;

	const char* SRs[3] = { "Kar98k", "M24", "AWM" };
	copy(SRs, SRs + 3, ostream_iterator<const char*, char>(cout, " "));
	cout << endl;

	vector<int> vctr(5);
	copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(), vctr.begin()); //istream_iterator<int, char>()-> like .end() iterator. Need to press ctrl + Z for EOF
	
	for (int i : vctr)
		cout << i << endl;

	int casts[10] = { 6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5 };
	vector<int> dice(10);
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	ostream_iterator<int, char> out_iter2(cout, " ");
	copy(dice.begin(), dice.end(), out_iter2);
	cout << endl;
	cout << "Implicit use of reverse iterator." << endl;
	copy(dice.rbegin(), dice.rend(), out_iter2);
	cout << endl;
	cout << "Explicit use of reverse iterator." << endl;
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << " ";

	cout << endl;
}