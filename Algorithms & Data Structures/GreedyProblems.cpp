#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

struct Actv {
	int start = -1;
	int finish = INT_MAX;
};

bool operator < (const Actv& av, const Actv& av2) {
	if (av.finish < av2.finish)
		return true;

	return false;
}

struct Item {
	double value = 0;
	int weight = 1;
};

bool operator < (const Item& it, const Item& it2) {
	double d = it.value / it.weight;
	double d2 = it2.value / it2.weight;

	if (d < d2)
		return true;

	return false;
}

void ActvSelection(Actv* arr, const int size) { //Activity Selection problem, Greedy algorithm that takes O(n*logn) time to execute.
	sort(arr, arr + size);
	Actv prev = arr[0];
	cout << prev.start << " " << prev.finish << endl;

	for(int i = 1; i < size; i++)
		if (prev.finish <= arr[i].start) {
			cout << arr[i].start << " " << arr[i].finish << endl;
			prev = arr[i];
		}
	cout << endl;
}

const int change(const int* arr, int& value, size_t size) { //Coin change problem, that uses greedy method and takes O(n) time to execute
	int coinNum = 0;										//and O(v) space complexity, where v is number of coins. However, it fails
	for (size_t i = 0; i < size; i++) {						//on some inputs and divide & concur solution is used for general solution
			while (value >= arr[i]) {
				value -= arr[i];
				coinNum++;
				cout << arr[i] << " ";
			}
			if (value == 0)
				break;
	}
	cout << endl << "Number of coins used: ";
	return coinNum;
}

const double Knapsack(Item* arr, const int capacity, const int size) {
	sort(arr, arr + size);
	int currcap = 0; double finalVal = 0.0;
	for (int i = size - 1; i >= 0; i--) {
		if (currcap + arr[i].weight <= capacity) {
			currcap += arr[i].weight;
			finalVal += arr[i].value;
			continue;
		}
		else {
			int remainder = capacity - currcap;
			double valPerWght = arr[i].value / double(arr[i].weight);
			finalVal += double(remainder) * valPerWght;
			currcap += remainder;
			break;
		}
		break;
	}
	cout << "Capacity: " << currcap << ", Final value: ";
	return finalVal;
}

int main() {
	Actv AV[6];
	for (int i = 0; i < 6; i++)
		cin >> AV[i].start >> AV[i].finish;
	
	cout << endl;
	int size = sizeof(AV) / sizeof(AV[0]);
	ActvSelection(AV, size);
	
	int coins[] = { 200, 100, 50, 20, 10, 5, 2, 1 };
	int size2 = sizeof(coins) / sizeof(coins[0]);
	int value = 0; cin >> value;
	cout << change(coins, value, size2) << endl;

	Item items[6];
	for (int i = 0; i < 6; i++)
		cin >> items[i].weight >> items[i].value;
	
	int size3 = sizeof(items) / sizeof(items[0]);
	int capacity = 0.0; cin >> capacity;
	cout << Knapsack(items, capacity, size3) << endl;
	
	return 0;
}