#include <iostream>
#include <future>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

void calcProducts(packaged_task<int(int, int)>& task, const vector<pair<int, int>>& pairs) {
	for (auto& pair : pairs) {
		auto fut = task.get_future();
		task(pair.first, pair.second); //calls packaged_task's function
		cout << pair.first << " * " << pair.second << " = " << fut.get() << endl;
		task.reset();
	}
}

int main(int argc, char** argv) {
	vector<pair<int, int>> allPairs;
	allPairs.push_back(make_pair(1, 2));
	allPairs.push_back(make_pair(2, 3));
	allPairs.push_back(make_pair(3, 4));
	allPairs.push_back(make_pair(4, 5));

	packaged_task<int(int, int)> task{ [](int fir, int sec) { return fir * sec; } };
	calcProducts(ref(task), allPairs);

	cout << endl;

	thread t(calcProducts, ref(task), allPairs);
	t.join();

	return 0;
}