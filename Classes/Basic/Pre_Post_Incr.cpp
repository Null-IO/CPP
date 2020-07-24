#include <iostream>
#include <cstdio>
using namespace std;

class Pre_Post_Incr {
private:
	int value = 0;
public:
	Pre_Post_Incr() {}
	Pre_Post_Incr(int x) : value(x) {}
	int getValue() const {return value;}
	int setValue(int x) {return value = x;}
	Pre_Post_Incr & operator ++ ();
	Pre_Post_Incr operator ++ (int);
	Pre_Post_Incr & operator -- ();
	Pre_Post_Incr operator -- (int);
};

Pre_Post_Incr & Pre_Post_Incr::operator ++ () {
	value += 1;
	return *this;
}

Pre_Post_Incr Pre_Post_Incr::operator ++ (int) {
	Pre_Post_Incr temp = *this;
	++(*this);
	return temp;
}

Pre_Post_Incr & Pre_Post_Incr::operator -- () {
	value -= 1;
	return *this;
}

Pre_Post_Incr Pre_Post_Incr::operator -- (int) {
	Pre_Post_Incr temp = *this;
	--(*this);
	return temp;
}

int main(int argc, char ** argv) {
	Pre_Post_Incr Z1(5);
	
	printf("%d ", ++Z1);
	printf("%d ", --Z1);
	printf("%d ", Z1++);
	printf("%d ", Z1--);
}


