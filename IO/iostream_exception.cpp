#include <iostream>
#include <cctype>
#include <exception>
using namespace std;

int main(int argc, char** argv) {
	// have failbit cause an exception to be thrown
	cin.exceptions(ios_base::failbit);
	cout << "Welcome you won't leave this place ever and will addup number till your eventual death(make stream fail to view sum)" << endl;
	int sum = 0;
	int input = 0;
	bool let_me_leave = false;

	while (!let_me_leave) {
		try {
			cout << "Enter numbers: ";
			while (cin >> input)
				sum += input;
		}
		catch (ios_base::failure& bf) {
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "Sum = " << sum << endl;

			continue;
		}
	}

	return 0;
}