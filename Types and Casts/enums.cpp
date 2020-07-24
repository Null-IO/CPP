#include <iostream>
#include <cstdio>
using namespace std;

enum car_manufacturer {TYT, NSSN, SBR};
enum car_model {SLE, SPA, IMPRZZ};

struct car {
	int manufacturer;
	int model;
};

void print_car(const car &c) {
	switch(c.manufacturer) {
		case TYT:
			printf("Toyota");
			break;
		case NSSN:
			printf("Nissan");
			break;
		case SBR:
			printf("Subaru");
			break;
			
	}
	switch(c.model) {
		case SLE:
			printf(" Skyline");
			break;
		case SPA:
			printf(" Supra");
			break;
		case IMPRZZ:
			printf(" Imprezzza");
			break;
	}
}

int main(int argc, char ** argv) {
	car carArr[3] = {
		{TYT, SPA}, {NSSN, SLE}, {SBR, IMPRZZ}
	};
	
	for(car c : carArr) {
		print_car(c);
		printf("\n");
	}
}


