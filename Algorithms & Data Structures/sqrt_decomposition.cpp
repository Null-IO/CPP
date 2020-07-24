//square root decomposition 0.0.1(testing is needed, but everything seems to work fine)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class sqrt_dec {
private:
	int* orig_arr = nullptr;
	vector<int> decomposed;
	const int block_size;
public:
	sqrt_dec(int* arr, const int n);
	const int query(const int begin, const int end) const;
	void update(const int var, const int index);
};

sqrt_dec::sqrt_dec(int* arr, const int n) : block_size(floor(sqrt(n))) {
	orig_arr = arr;
	int sum = 0;
	for (size_t i = 0; i < n; i++) {
		sum += orig_arr[i];

		if ((i + 1) % block_size == 0) {
			decomposed.push_back(sum);
			sum = 0;
		}
	}
}

const int sqrt_dec::query(const int begin, const int end) const {
	int _begin = begin - 1;
	int sum = 0;
	
	int dec_idx = floor((double)_begin / (double)block_size);

	while (_begin < end) {
		if ((_begin) % block_size == 0 && (_begin + block_size) <= end) {
			sum += decomposed[dec_idx++];
			_begin += block_size;
		}
		else {
			sum += orig_arr[_begin];
			_begin++;
		}
	}
	return sum;
}

void sqrt_dec::update(const int var, const int index) {
	int dec_idx = floor((double)(__int64(index) - 1) / (double)block_size);
	int diff = var - orig_arr[index - 1];
	decomposed[dec_idx] += diff;
	orig_arr[index - 1] = diff;
}

int main() {
	int arr[] = { 1, 2, 0, 7, 4, 2, 5, 0, 1, 3 };
	
	sqrt_dec z(arr, 10);

	cout << z.query(4, 7) << endl;

	return 0;
}

