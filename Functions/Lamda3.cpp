#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <functional>
using namespace std;

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

int main(int argc, char** argv) {
	vector<int> numbers(Size1);
	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);

	// using function pointers
	cout << "Sample size = " << Size1 << '\n';
	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	int count13 = count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	numbers.resize(Size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size2 << endl;

	// using a functor
	class f_mod
	{
	private:
		int dv;
	public:
		f_mod(int d = 1) : dv(d) {}
		bool operator()(int x) { return x % dv == 0; }
	};

	count3 = std::count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	numbers.resize(Size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size3 << endl;

	auto mod = [](int x, int y) { return x % y == 0; };
	count3 = std::count_if(numbers.begin(), numbers.end(), bind(mod, placeholders::_1, 3)); //bind1st and bind2nd is removed prior to C++17
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	count13 = std::count_if(numbers.begin(), numbers.end(), bind(mod, placeholders::_1, 13));
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	//OR
	cout << "Regenerating and resizing numbers:" << endl;
	numbers.resize(Size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size2 << endl;

	count3 = count13 = 0;
	for_each(numbers.begin(), numbers.end(), [&count3, &count13](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; }); //access count3 by reference, [count3] by value, [&] access all variables by reference, [=] access all variables by value

	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	cout << "Count of numbers divisible by 13: " << count13 << "\n\n";

	return 0;
}