#include <iostream>
#include <thread>
#include <random>
#include <future>
#include <numeric>
#include <vector>
using namespace std;

static const size_t NUM = 100000000;

long long getDotProduct(vector<long long>& v, vector<long long>& w) {
	auto vSize = v.size();

	auto future1 = async([&] {
		return inner_product(v.begin(), v.begin() + (vSize / 4), w.begin(), 0LL);
		});

	auto future2 = async([&] {
		return inner_product(v.begin() + (vSize / 4), v.begin() + (vSize / 2), w.begin() + (vSize / 4), 0LL);
		});

	auto future3 = async([&] {
		return inner_product(v.begin() + (vSize / 2), v.begin() + (vSize * 3 / 4), w.begin() + (vSize / 2), 0LL);
		});

	auto future4 = async([&] {
		return inner_product(v.begin() + (vSize * 3 / 4), v.end(), w.begin() + (vSize * 3 / 4), 0LL);
		});

	return __int64(future1.get()) + __int64(future2.get()) + __int64(future3.get()) + __int64(future4.get());
}

int main(int argc, char** argv) {
	random_device seed;
	mt19937 engine(seed());
	uniform_int_distribution<int> dist(0, 100);

	vector<long long> v; v.reserve(NUM);
	vector<long long> w;  w.reserve(NUM);

	for (size_t i = 0; i < NUM; i++) {
		v.push_back(dist(engine));
		w.push_back(dist(engine));
	}

	cout << "getDotProduct(v, w): " << getDotProduct(v, w) << endl;

	return 0;
}