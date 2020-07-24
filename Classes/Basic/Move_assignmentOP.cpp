#include <iostream>
#include <utility>
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
	Useless& operator = (const Useless& f); // copy assignment
	Useless& operator = (Useless&& f); // move assignment
	void ShowData() const;
	~Useless();
};

int Useless::ct = 0;

Useless::Useless() {
	++ct;
	n = 0;
	pc = nullptr;
}

Useless::Useless(int k) : n(k) {
	++ct;
	pc = new char[n] {};
}

Useless::Useless(int k, char ch) : n(k) {
	++ct;
	pc = new char[n] {};
	for (int i = 0; i < n; i++)
		pc[i] = ch;
}

Useless::Useless(const Useless& f) : n(f.n) {
	++ct;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];	
}

Useless::Useless(Useless&& f) : n(f.n) {
	++ct;
	pc = f.pc; // steal address
	f.pc = nullptr; // give old object nothing in return
	f.n = 0;
}

Useless Useless::operator + (const Useless& f) const {
	Useless temp = Useless(n + f.n);
	
	for (size_t i = 0; i < n; i++)
		temp.pc[i] = pc[i];

	for (size_t i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];

	return temp;
}

Useless& Useless::operator = (const Useless& f) {
	cout << "copy assignment operator called:" << endl;
	if (this == &f)
		return *this;

	delete[] pc;
	n = f.n;
	pc = new char[n] {};
	for (size_t i = 0; i < n; i++)
		pc[i] = f.pc[i];
	
	return *this;
}

Useless& Useless::operator = (Useless&& f) {
	cout << "move assignment operator called:" << endl;
	if (this == &f)
		return *this;

	delete[] pc;
	n = f.n;
	pc = f.pc;

	f.n = 0;
	f.pc = nullptr;

	return *this;
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
	delete[] pc;
}

int main(int argc, char** argv) {	
	{
		Useless one(10, 'x');
		Useless two = one + one; // calls move constructor
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		Useless three, four;
		cout << "three = one\n";
		three = one; //automatic move assignment
		cout << "now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two; // automatic move assignment
		cout << "now object four = ";
		four.ShowData();
		cout << "four = move(one)" << endl;
		four = move(one); //force move assignment
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();

		return 0;
	}
}