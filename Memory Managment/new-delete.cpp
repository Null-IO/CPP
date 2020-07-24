#include <iostream>
#include <cstdio>
#include <new>
using namespace std;

class A {
private:
	int a = 0;
	int b = 0;
	int c = 0;
public:
	A(int i = 0) : a(i), b(i + 1), c(i + 2) {printf("constructor is being called\n");};
	int get_a() const { return a; }
	int get_b() const { return b; }
	int get_c() const { return c; }
	~A() {printf("deconstructor is being called\n");};
};

int main(int argc, char ** argv) {
	printf("allocating space for objects\n");
	A *a = new (nothrow) A[3];
	if(a == nullptr) {
		printf("new A failed\n");
		return 1;
	}
	printf("a: %d, %d, %d\n", a ->get_a(), a ->get_b(), a ->get_c());
	delete[] a;
	printf("object has been destroyed\n");
	
	return 0;
}


