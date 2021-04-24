#include <iostream>
#include <random>
using namespace std;

const double approx_pi(default_random_engine& engine, const uniform_real_distribution<double>& dist, const int n) {
	int in_circle = 0;
	int total = 0;

	for (size_t i = 0; i < n; i++)
	{
		const double x = dist(engine);
		const double y = dist(engine);
		
		if(sqrt(pow(x, 2) + pow(y, 2)) < 1.0)
			in_circle++;
	
		total++;
	}
	return 4.0 * in_circle / total;
}

int main(int argc, char** argv) {
	random_device seed;
	default_random_engine engine;
	uniform_real_distribution<double> dist(0.0, 1.0);

	cout << approx_pi(engine, dist, 100000) << endl;

	return 0;
}