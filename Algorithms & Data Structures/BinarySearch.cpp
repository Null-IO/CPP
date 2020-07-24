#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int FindMid(int Arr[], int Start, int End) {
	return (Start + End) / 2;
}

int BinarySearch(int Arr[], int FindNum, int Start, int End) {
	int Median;
	
	if(Start == End) {
		if(Arr[Start] == FindNum)
			return Start;
		else
			return -1;
	}
	
	Median = FindMid(Arr, Start, End);
	
	if(Arr[Median] < FindNum)
		return BinarySearch(Arr, FindNum, Median, End);
	else if(Arr[Median] > FindNum)
		return BinarySearch(Arr, FindNum, Start, Median);
	else if(Arr[Median] == FindNum)
		return Median;
	
}

int main(int argc, char ** argv) {
	int n, FindNum; cin >> n >> FindNum;
	int Arr[n];
	
	for(int i = 0; i < n; i++)
		cin >> Arr[i];
	
	sort(Arr, Arr + n);
	
	cout << BinarySearch(Arr, FindNum, 0, n);
}


