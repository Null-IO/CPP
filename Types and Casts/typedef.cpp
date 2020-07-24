#include <iostream>
#include <cstdio>
using namespace std;

typedef uint8_t point_t;
typedef unsigned char rank_t;

struct score {
	point_t p;
	rank_t r;
};

int main(int argc, char ** argv) {
	score s = {5, 1};
	printf("score s has %d points and rank of %d\n", s.p, s.r);
	return 0;
}


