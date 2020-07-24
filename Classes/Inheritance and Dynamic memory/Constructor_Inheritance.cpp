#include <iostream>
#include <utility>
using namespace std;

class BS {
	int q;
	double w;
public:
	BS() : q(0), w(0) {}
	BS(int k) : q(k), w(100) {}
	BS(double x) : q(-1), w(x) {}
	BS(int k, double x) : q(k), w(x) {}
	int fn(int j) { cout << "int " << j << " in BS" << endl; return j; }
	double fn(double w) { cout << "double " << w << " in BS" << endl; return w; }
	void Show() const { std::cout << q << ", " << w << '\n'; }
};
class DR : public BS
{
	short j;
public:
	using BS::BS;
	using BS::fn;
	DR() : j(-100) {} // DR needs its own default constructor
	DR(double x) : BS(2 * x), j(int(x)) {}
	DR(int i) : j(-2), BS(i, 0.5 * i) {}
	double fn(double w) { cout << "double " << w << " in DR" << endl; return w; } //fn is not carried from BS
	void Show() const { std::cout << j << ", "; BS::Show(); }
};

int main(int argc, char** argv) {
	DR o1; // use DR()
	DR o2(18.81); // use DR(double) instead of BS(double)
	DR o3(10, 1.8); // use BS(int, double)
	o1.fn(5);
	o1.fn(5.21);
	return 0;
}