//This doesn't compile!!!
#include <iostream>
#include <utility>
using namespace std;

class Action
{
	int a;
public:
	Action(int i = 0) : a(i) {}
	int val() const { return a; };
	virtual void f(char ch) const { std::cout << val() << ch << "\n"; }
	virtual void z(char ch) const final { std::cout << val() << ch + a << "\n"; } //Can't be overriden in a derived class
};
class Bingo : public Action
{
public:
	Bingo(int i = 0) : Action(i) {}
	virtual void f(char* ch) const override { std::cout << val() << ch << "!\n"; } //causes error now
	virtual void z(char ch) const final { std::cout << val() << ch + a << "\n"; }
};

int main(int argc, char** argv) {	
	
	return 0;
}