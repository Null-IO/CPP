#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

typedef unique_ptr<int[]> smart_array;
typedef unique_ptr<smart_array[]> smart_array3D;

//Top-down approach
long long FibonacciTD(long long* temp, int n) {
	if (n < 1) {
		cout << "Error!" << endl;
		return -1;
	}
	else if (n == 1)
		return 0;
	else if (n == 2)
		return 1;

	if (temp[n] == 0)
		temp[n] = FibonacciTD(temp, n - 1) + FibonacciTD(temp, n - 2);
	else
		return temp[n];
		
}

//Bottom-up approach
long long FibonacciBU(long long* temp, int n) {
	for (int i = 3; i <= n; i++)
		temp[i] = temp[i - 1] + temp[i - 2];

	return temp[n];
}

int coinChange(int change, int* coinArr, int n) {
	if (change == 0)
		return 1;
	else if (change < 0 || n < 0)
		return 0;
	else
		return coinChange(change, coinArr, n - 1) + coinChange(change - coinArr[n], coinArr, n);
}

//Top-down approach
int NumberFactorTD(int change, int n, int* coinArr, smart_array* temp) {
	if (change < 0 || n < 0)
		return 0;
	else if (change == 0)
		return 1;

	if (temp[change][n] == 0)
		temp[change][n] = NumberFactorTD(change, n - 1, coinArr, temp) + NumberFactorTD(change - coinArr[n], n, coinArr, temp);

	return temp[change][n];
	
}

//Bottom-up approach
int NumberFactorBU(int change, int n, int* coinArr) {
	int x = 0, y = 0;

	int vSize = change + 1;
	auto table = unique_ptr<smart_array[]>(new smart_array[vSize]{});
	for (int i = 0; i < vSize; i++)
		table[i] = smart_array(new int[n] {});

	for (int j = 0; j < n; j++)
		table[0][j] = 1;

	for (int i = 1; i < vSize; i++) {
		for (int j = 0; j < n; j++) {
			x = (i - coinArr[j] >= 0) ? table[i - coinArr[j]][j] : 0;
			y = (j >= 1) ? table[i][j - 1] : 0;

			table[i][j] = x + y;
		}
	}
	return table[change][n - 1];
}

//Top-down approach
int HouseThiefTD(int* Houses, size_t s, int* temp, int index = 0) {
	if (index >= s)
		return 0;

	if (temp[index] == 0) {
		int steal = Houses[index] + HouseThiefTD(Houses, s, temp, index + 2);
		int skip = HouseThiefTD(Houses, s, temp, index + 1);
		temp[index] = max(steal, skip);
	}
	return temp[index];
}

//Bottom-up approach
int HouseThiefBU(int* Houses, int s) {
	unique_ptr<int[]> temp(new int[s]);
	temp[s - 1] = Houses[s - 1];
	int a = 0, b = 0;

	for (int i = s - 2; i >= 0; i--) {
		a = ((i + 2) < s) ? Houses[i] + temp[i + 2] : 0;
		b = ((i + 1) < s) ? temp[i + 1] : 0;

		temp[i] = max(a, b);
	}

	return temp[0];
}

//Top-down approach
int convert_str(const string& trgt, const string& orig, smart_array* temp, int Tidx = 0, int Oidx = 0) {
	if (temp[Tidx][Oidx] == 0) {
		if (Tidx == trgt.size())
			temp[Tidx][Oidx] = orig.size() - Oidx;
		else if (Oidx == orig.size())
			temp[Tidx][Oidx] = trgt.size() - Tidx;
		else if (trgt[Tidx] == orig[Oidx])
			temp[Tidx][Oidx] = convert_str(trgt, orig, temp, Tidx + 1, Oidx + 1);
		else {
			int insrt = convert_str(trgt, orig, temp, Tidx, Oidx + 1);
			int rmv = convert_str(trgt, orig, temp, Tidx + 1, Oidx);
			int rplc = convert_str(trgt, orig, temp, Tidx + 1, Oidx + 1);

			temp[Tidx][Oidx] = 1 + min({ rmv, insrt, rplc });
		}
	}

	return temp[Tidx][Oidx];
}

//Bottom-up approach
int convert_str(const string& trgt, const string& orig) {
	auto temp = unique_ptr<smart_array[]>(new smart_array[trgt.size() + 1]{});
	for (size_t i = 0; i < trgt.size() + 1; i++)
		temp[i] = smart_array(new int[orig.size() + 1]{});
	
	for (size_t i = 0, j = 0; i <= orig.size() && j <= trgt.size(); i++, j++) {
		temp[trgt.size()][i] = orig.size() - i;
		temp[j][orig.size()] = trgt.size() - j;
		
	}
	for (int i = trgt.size() - 1; i >= 0; i--) {
		for (int j = orig.size() - 1; j >= 0; j--) {
			if (trgt[i] == orig[j])
				temp[i][j] = temp[i + 1][j + 1];
			else
				temp[i][j] = 1 + min({ temp[i][j + 1], temp[i + 1][j], temp[i + 1][j + 1] });
		}
	}
	return temp[0][0];
}
//Top-down approach(Interestingly, this problem doesn't have overlapping sub-problem, but we can still use dynamic programming without additional speed gain)
int zero_one_knapsack(int capacity, pair<int, int>* items, smart_array* temp, int n, int index = 0) {
	if (capacity <= 0 || index >= n)
		return 0;
	if (temp[index][capacity] != 0)
		return temp[index][capacity];

	int profit1 = 0;
	if (items[index].second <= capacity)
		profit1 = items[index].first + zero_one_knapsack(capacity - items[index].second, items, temp, n, index + 1);
	
	int profit2 = zero_one_knapsack(capacity, items, temp, n, index + 1);
	temp[index][capacity] = max(profit1, profit2);
	
	return temp[index][capacity];
}

//Bottom-up approach
int zero_one_knapsack(int capacity, pair<int, int>* items, int n) {	
	auto tempArr = unique_ptr<smart_array[]>(new smart_array[__int64(n) + 1]{}); //n + 1 is need to access the whole items[]
	for (size_t i = 0; i <= n; i++)
		tempArr[i] = smart_array(new int[__int64(capacity) + 1]{});

	for (int r = n - 1; r >= 0; r--) {
		for (int c = 1; c <= capacity; c++) {
			int profit1 = 0, profit2 = 0;
			if (items[r].second <= c)
				profit1 = items[r].first + tempArr[__int64(r) + 1][__int64(c) - items[r].second];
				
			profit2 = tempArr[__int64(r) + 1][c];
			
			tempArr[r][c] = max(profit1, profit2);
		}
	}
	return tempArr[0][capacity];
}
//Top-down approach
int LCS(const string& s1, const string& s2, smart_array* temp, int s1i = 0, int s2i = 0) {
	if (s1i >= s1.size() || s2i >= s2.size())
		return 0;
	
	if (temp[s1i][s2i] != 0)
		return temp[s1i][s2i];
	
	if (s1[s1i] == s2[s2i])
		temp[s1i][s2i] = 1 + LCS(s1, s2, temp, s1i + 1, s2i + 1);
	else {
		int m1 = LCS(s1, s2, temp, s1i + 1, s2i);
		int m2 = LCS(s1, s2, temp, s1i, s2i + 1);
		temp[s1i][s2i] = max(m1, m2);
	}
	return temp[s1i][s2i];
}
//Bottom-up approach
int LCS(const string& s1, const string& s2) {
	auto tempArr = unique_ptr<smart_array[]>(new smart_array[s1.size() + 1]{});
	for (size_t i = 0; i < s1.size() + 1; i++)
		tempArr[i] = smart_array(new int[s2.size() + 1]{});

	for (size_t i = s1.size(); i-- > 0 ;) { //starts with s1.size() - 1
		int x1 = 0, x2 = 0;
		for (size_t j = s2.size(); j-- > 0 ;) {
			if (s1[i] == s2[j])
				tempArr[i][j] = 1 + tempArr[i + 1][j + 1];
			else {
				x1 = tempArr[i][j + 1];
				x2 = tempArr[i + 1][j];
				tempArr[i][j] = max(x1, x2);
			}
		}
	}
	
	return tempArr[0][0];
}
//Top-down approach
int LPS(const string& s, smart_array* temp, int bw, int fw = 0) {
	if (fw > bw)
		return 0;

	if (temp[fw][bw] != 0)
		return temp[fw][bw];
	else if(fw == bw)
		temp[fw][bw] = 1;
	else if (s[fw] == s[bw])
		temp[fw][bw] = 2 + LPS(s, temp, bw - 1, fw + 1);
	else {
		int forward = LPS(s, temp, bw, fw + 1);
		int backward = LPS(s, temp, bw - 1, fw);

		temp[fw][bw] = max(forward, backward);
	}
	return temp[fw][bw];
}
//Bottom-up approach
int LPS(const string& s) {
	auto temp = unique_ptr<smart_array[]>(new smart_array[s.size() + 1]{});
	for (size_t i = 0; i < s.size() + 1; i++)
		temp[i] = smart_array(new int[s.size() + 1]{});

	for (size_t i = 0; i < s.size(); i++) {
		for (size_t j = s.size() - 1; j-- > 0 ;) {
			if (j <= i) {
				if (i == j)
					temp[j][i] = 1;
				else if (s[i] == s[j])
					temp[j][i] = 2 + temp[j + 1][i - 1];
				else
					temp[j][i] = max(temp[j + 1][i], temp[j][i - 1]);
			}
		}
	}
	return temp[0][s.size() - 1];
}

int MinCost(int x, int y, smart_array* Mtrx, smart_array* temp) {
	if (x <= 0 || y <= 0)
		return USHRT_MAX;

	if (temp[x][y] != 0)
		return temp[x][y];

	if (x == 1 && y == 1)
		temp[x][y] = Mtrx[0][0];
	else
		temp[x][y] = Mtrx[x - 1][y - 1] + min(MinCost(x - 1, y, Mtrx, temp), MinCost(x, y - 1, Mtrx, temp));
	
	return temp[x][y];
}

int MinCost(int x, int y, smart_array* Mtrx) {
	auto temp = unique_ptr<smart_array[]>(new smart_array[x + 1]{});
	for (size_t i = 0; i <= x; i++)
		temp[i] = smart_array(new int[y + 1] {});
	
	for (size_t i = 0; i <= x; i++)
			temp[i][0] = USHRT_MAX;

	for (size_t j = 0; j <= y; j++)
		temp[0][j] = USHRT_MAX;

	temp[0][1] = 0;
	for (size_t i = 1; i <= x; i++)
		for (size_t j = 1; j <= y; j++)
			temp[i][j] = Mtrx[i - 1][j - 1] + min(temp[i - 1][j], temp[i][j - 1]);

	return temp[x][y];
}

int numOfWays(int x, int y, int cost, smart_array* Matrix, smart_array3D* temp) { //Number of ways to reach end of array with given cost
	if (x < 0 || y < 0 || cost < 0)
		return 0;

	if (x == 0 && y == 0)
		return ((cost - Matrix[0][0]) >= 0) ? 1 : 0;
	
	if (temp[x][y][cost] == 0)
		temp[x][y][cost] = numOfWays(x - 1, y, cost - Matrix[x][y], Matrix, temp) + numOfWays(x, y - 1, cost - Matrix[x][y], Matrix, temp);
	
	return temp[x][y][cost];
}

int LPs(const string& s1, smart_array* temp, int bw, int fw = 0) { //Longest Palindromic Substring
	if (fw >= s1.size() || bw < 0)
		return 0;
	else if (fw == bw)
		temp[fw][bw] = 1;
	else if (temp[fw][bw] == 0) {
		int z = 0;
		if (s1[fw] == s1[bw]) {
			int remaining_lngth = bw - fw - 1;
			if (remaining_lngth == LPs(s1, temp, bw - 1, fw + 1))
				z = remaining_lngth + 2;
		}
		int forward = LPs(s1, temp, bw, fw + 1);
		int backward = LPs(s1, temp, bw - 1, fw);

		temp[fw][bw] = max({ forward, backward, z });
	}
	return temp[fw][bw];
}

int main(int argc, char** argv) {
	//Temp arrays must be nullfied before second use of the same function
	//__int64 is used to solve arithmetic overflow warning
	/*
	int n = 50;
	unique_ptr<long long[]> fibArr(new long long[n + 1]{});
	fibArr[1] = 0; fibArr[2] = 1; //fibArr[0] is dummy
	cout << "Top-down approach(Fibonacci Series): " << FibonacciTD(fibArr.get(), n) << endl;
	cout << "Bottom-up approach(Fibonacci Series): " << FibonacciBU(fibArr.get(), n) << endl;

	int coinArr[5] = { 1, 5, 10, 25, 50 }; int change = 1000; int numArrSize = change + 1; int coinSize = sizeof(coinArr) / sizeof(coinArr[0]);

	auto TwoDim = unique_ptr<smart_array[]>(new smart_array[numArrSize]{});
	for (size_t i = 0; i < numArrSize; i++)
		TwoDim[i] = smart_array(new int[coinSize] {});

	cout << "Top-down approach(Coin Change Problem): " << NumberFactorTD(change, coinSize - 1, coinArr, TwoDim.get()) << endl;
	cout << "Bottom-up approach(Coin Change Problem): " << NumberFactorBU(change, coinSize, coinArr) << endl;

	int House[7] = { 6, 7, 1, 30, 8, 2, 4 }; size_t houseSize = sizeof(House) / sizeof(House[0]);
	unique_ptr<int[]> temp(new int[houseSize]{});
	cout << "Top-down approach(House Theif Problem): " << HouseThiefTD(House, houseSize, temp.get()) << endl;
	cout << "Bottom-up approach(House Theif Problem): " << HouseThiefBU(House, houseSize) << endl;

	string s1 = "tbres"; string s2 = "table";
	auto indexes = unique_ptr<smart_array[]>(new smart_array[s1.size() + 1]{});
	for (size_t i = 0; i < s1.size() + 1; i++)
		indexes[i] = smart_array(new int[s2.size() + 1] {});

	cout << "Top-down approach(Convert String Problem): " << convert_str(s1, s2, indexes.get()) << endl;
	cout << "Bottom-up approach(Convert String Problem): " << convert_str(s1, s2) << endl;

	const int n = 4, cap = 7; pair<int, int> items[4] = { {31, 3}, {26, 1}, {72, 5}, {17, 2} };

	auto tempArr = unique_ptr<smart_array[]>(new smart_array[n]{});
	for (size_t i = 0; i < n; i++)
		tempArr[i] = smart_array(new int[__int64(cap) + 1] {});

	cout << "Top-down approach(0/1 Knapsack Problem): " << zero_one_knapsack(cap, items, tempArr.get(), n) << endl;
	cout << "Bottom-down approach(0/1 Knapsack Problem): " << zero_one_knapsack(cap, items, n) << endl;

	string s1 = "numberphile", s2 = "computerphile";
	auto tempArr = unique_ptr<smart_array[]>(new smart_array[s1.size()]{});
	for (size_t i = 0; i < s1.size(); i++)
		tempArr[i] = smart_array(new int[s2.size()]{});

	cout << "Top-down approach(Longest Common Subsequence Problem): " << LCS(s1, s2, tempArr.get()) << endl;
	cout << "bottom-up approach(Longest Common Subsequence Problem): " << LCS(s1, s2) << endl;

	string s = "ELRMENMET";
	auto tempArr = unique_ptr<smart_array[]>(new smart_array[s.size()]{});
	for (size_t i = 0; i < s.size(); i++)
		tempArr[i] = smart_array(new int[s.size()]{});

	cout << "Top-down approach(Longest Palindromic Substring Problem): " << LPS(s, tempArr.get(), s.size() - 1) << endl;
	cout << "bottom-up approach(Longest Palindromic Substring Problem): " << LPS(s) << endl;

	const int x = 5, y = 5;
	int Matrix[x][y] = {
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
	};

	auto Mtrx = unique_ptr<smart_array[]>(new smart_array[x]{});
	for (size_t i = 0; i < x; i++)
		Mtrx[i] = smart_array(new int[y] {});

	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < y; j++)
			Mtrx[i][j] = Matrix[i][j];

	auto tempArr = unique_ptr<smart_array[]>(new smart_array[x + 1]{});
	for (size_t i = 0; i <= x; i++)
		tempArr[i] = smart_array(new int[y + 1]{});

	cout << "Top-down approach(Minimum cost to reach the end of an array Problem): " << MinCost(x, y, Mtrx.get(), tempArr.get()) << endl;
	cout << "Bottom-up approach(Minimum cost to reach the end of an array Problem): " << MinCost(x, y, Mtrx.get()) << endl;

	//unique_ptr<int[]> smart_array;
	const int x = 5, y = 5, cost = 36;
	int Matrix[x][y] = {
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
	};
	auto Mtrx = unique_ptr<smart_array[]>(new smart_array[x]{});
	for (size_t i = 0; i < x; i++)
		Mtrx[i] = smart_array(new int[y] {});

	for (size_t i = 0; i < x; i++)
		for (size_t j = 0; j < y; j++)
			Mtrx[i][j] = Matrix[i][j];

	auto a1 = unique_ptr<smart_array3D[]>(new smart_array3D[x]{});
	for (size_t i = 0; i < x; i++) {
		a1[i] = smart_array3D(new smart_array[y]{});
		for (size_t j = 0; j < y; j++) {
			a1[i][j] = smart_array(new int[cost + 1]{});
		}
	}
	//Null the temp array before using Numberofways!!!
	cout << numOfWays(x - 1, y - 1, cost, Mtrx.get(), a1.get()) << endl;
	*/
	string s1 = "ZQX";
	auto tempArr = unique_ptr<smart_array[]>(new smart_array[s1.size() + 1]{});
	for (size_t i = 0; i <= s1.size(); i++)
		tempArr[i] = smart_array(new int[s1.size() + 1]{});

	cout << LPs(s1, tempArr.get(), s1.size()) << endl;

}