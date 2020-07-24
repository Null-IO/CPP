#include <iostream>
const int SLEN = 10;
inline void eatline() { 
	while (std::cin.get() != '\n') 
		continue; 
}

int main() {
	using std::cout; using std::endl; using std::cin;
	
	char ch;

	while (cin.get(ch)) { //I used a #3 pencil when I should have used a #2.
		if (ch != '#')
			cout << ch;
		else {
			cin.putback(ch); 
			break;
		}
	}

	if (!cin.eof()) {
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else {
		cout << "End of file reached.\n";
		std::exit(0);
	}

	while (cin.peek() != '#') { // look ahead
		cin.get(ch);
		cout << ch;
	}

	if (!cin.eof()) {
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	} else
		cout << "End of file reached.\n";
	
	cout << "Remaining characters in the stream: ";
	while (cin.peek() != '\n') { // look ahead
		cin.get(ch);
		cout << ch;
	}
	eatline();
	cout << endl << "-------------------------" << endl;

	char name[SLEN];
	char title[SLEN];
	
	cout << "Enter your name: ";
	cin.get(name, SLEN);
	
	if (cin.peek() != '\n')
		cout << "Sorry, we only have enough room for " << name << endl;
	
	eatline(); //clean the stream(even if fitted into buffer, cin.get(ch) leave '\n')
	
	cout << "Dear " << name << ", enter your title: \n";
	cin.get(title, SLEN);
	
	if (cin.peek() != '\n')
		cout << "We were forced to truncate your title.\n";
	
	eatline();
	cout << "Name: " << name
		<< "\nTitle: " << title << endl;

	return 0;
}