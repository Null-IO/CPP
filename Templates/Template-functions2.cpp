#include <iostream>
#include <cstdlib>
using namespace std;

struct Z {
	string name = "";
	int age = 0;
};

template<typename T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
// explicit specialization for the Z type
template <> void Swap<Z>(Z& a, Z& b) {
	int temp = a.age;
	a.age = b.age;
	b.age = temp;
}

int main(int argc, char** argv) {
	double a = 13.29; double b = 17.13; int i = 61;
	Swap(a, b);
	cout << a << " " << b << endl;

	Z s1; s1.age = 19; s1.name = "Zuka";
	Z s2; s2.age = 10; s2.name = "Gio";

	Swap(s1, s2);
	cout << s1.name << " " << s1.age << " " << s2.name << " " << s2.age << endl;

	return 0;
}

/*
template <class T>
void Swap (T &, T &); // template prototype
template <> void Swap<job>(job &, job &); // explicit specialization for job

int main(void)
{
template void Swap<char>(char &, char &); // explicit instantiation for char(give compiler instructions to generate specific function prematurely!!!)
short a, b;
...
Swap(a,b); // implicit template instantiation for short
job n, m;
...
Swap(n, m); // use explicit specialization for job
char g, h;
...
Swap(g, h); // use explicit template instantiation for char
...
}
*/
