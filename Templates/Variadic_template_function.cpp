#include <iostream>
#include <string>
using namespace std;

void show_list() {}; //terminates recursion

template<typename T>
void show_list(const T& value) {
	std::cout << value << '\n';
}

template<typename T, typename... Args>
void show_list(const T& value, const Args&... args) {
	cout << value << ", "; //decreases size of args by 1 everytime
	show_list(args...);
}

int main(int argc, char** argv) {
	int n = 14;
	double x = 2.71828;
	std::string mr = "Mr. String objects!";
	show_list(n, x);
	show_list(x * x, '!', 7, mr);

	return 0;
}