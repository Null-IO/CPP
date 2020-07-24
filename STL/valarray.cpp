#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

int main() {
	using namespace std;
	vector<double> data;
	double temp;

	cout << "Enter numbers (<=0 to quit):" << endl;
	while (cin >> temp && temp > 0)
		data.push_back(temp);
	
	sort(data.begin(), data.end());
	int size = data.size();
	valarray<double> numbers(size);
	
	for (int i = 0; i < size; i++)
		numbers[i] = data[i];

	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0 * sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);

	for (int i = 0; i < size; i++) {
		cout.width(10);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}

	return 0;
}