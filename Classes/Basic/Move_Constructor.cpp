#include <iostream>
#include <cmath>
using namespace std;

class Useless {
private:
	int n;
	char* pc;
	static int ct;
	void showObject() const;
public:
	Useless();
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless& f); //regular copy constructor
	Useless(Useless&& f); //move constructor(). A move constructor may alter its argument in the process of transferring ownership to a new object, and this implies that an rvalue reference parameter should not be const.
	Useless operator + (const Useless& f) const;
	void ShowData() const;
	~Useless();
};

int Useless::ct = 0;

Useless::Useless() {
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called; number of objects: " << ct << endl;
	showObject();
}

Useless::Useless(int k) : n(k) {
	++ct;
	cout << "(int) constructor called; number of objects: " << ct << endl;
	pc = new char[n] {};
	showObject();
}

Useless::Useless(int k, char ch) : n(k) {
	++ct;
	cout << "(int, char) constructor called; number of objects: " << ct << endl;
	pc = new char[n] {};
	for (int i = 0; i < n; i++)
		pc[i] = ch;
	
	showObject();
}

Useless::Useless(const Useless& f) : n(f.n) {
	++ct;
	cout << "copy const called; number of objects: " << ct << endl;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	
	showObject();
}

Useless::Useless(Useless&& f) : n(f.n) {
	++ct;
	cout << "move constructor called; number of objects: " << ct << endl;
	pc = f.pc; // steal address
	f.pc = nullptr; // give old object nothing in return
	f.n = 0;
	showObject();
}

Useless Useless::operator + (const Useless& f) const {
	cout << "Entering operator+()" << endl;
	Useless temp = Useless(n + f.n);
	
	for (size_t i = 0; i < n; i++)
		temp.pc[i] = pc[i];

	for (size_t i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];

	cout << "temp object:" << endl;
	cout << "Leaving operator+()" << endl;
	return temp;
}

void Useless::showObject() const {
	cout << "Number of elements: " << n;
	cout << " Data address: " << (void*)pc << endl;
}

void Useless::ShowData() const {
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; i++)
			cout << pc[i];
	cout << endl;
}

Useless::~Useless() {
	cout << "destructor called; objects left: " << --ct << endl;
	cout << "deleted object:\n";
	showObject();
	delete[] pc;
}

int main(int argc, char** argv) {	
	{
		Useless one(10, 'x');
		Useless two = one; // calls copy constructor
		Useless three(20, 'o');
		Useless four(one + three); // calls operator+(), move constructor
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << "object three: ";
		three.ShowData();
		cout << "object four: ";
		four.ShowData();

		return 0;
	}
}