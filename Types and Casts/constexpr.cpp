#include <iostream>
using namespace std;

class MyDouble { //constexpr user defined type, which follows all of the constexpr rules
private:
	double d1;
	double d2;
public:
	constexpr MyDouble(double d1_, double d2_) : d1(d1_), d2(d2_) {};
	constexpr double getSum() const { return d1 + d2; }
};

int main(int argc, char** argv) {
	constexpr double myStatVal = 2.0;
	constexpr MyDouble myStatic(10.5, myStatVal);
	constexpr double sumStat = myStatic.getSum();

	cout << "myStatVal = " << myStatVal << endl;
	cout << "sumStat = " << sumStat << endl;

	return 0;
}