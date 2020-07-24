#include <iostream>
#include <cstdio>
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	int placeholder;
	
	for(int j = low; j <= high - 1; j++) {
		if(arr[j] <= pivot) {
			i++;
			
			placeholder = arr[j];
			arr[j] = arr[i];
			arr[i] = placeholder;
		}
	}
	
	placeholder = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = placeholder;
	
	return (i + 1);
}

void qsort(int arr[], int low, int high) {
	if(low < high) {
		int z = partition(arr, low, high);
		
		qsort(arr, low, z - 1);
		qsort(arr, z + 1, high);
	
	}
}

int main(int argc, char ** argv) {
	int n; cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	qsort(arr, 0, n - 1);
	
	for(int i : arr)
		printf("%d ", i);	
}


