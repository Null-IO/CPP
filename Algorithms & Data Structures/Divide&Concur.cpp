#include <iostream>
#include <algorithm>
using namespace std;

int coinArr[5] = { 1, 5, 10, 25, 50 };
int House[7] = { 6, 7, 1, 30, 8, 2, 4 };
pair<int, int> items[3] = { {60, 10}, {100, 20}, {120, 30} };
int Matrix[5][5] = {
	{4, 7, 8, 6, 4},
	{6, 7, 3, 9, 2},
	{3, 8, 1, 2, 4},
	{7, 1, 7, 3, 7},
	{2, 9, 8, 9, 3}
};

int coinChange(int change, int n = 4) {
	if (change == 0)
		return 1;
	else if (change < 0 || n < 0)
		return 0;
	else
		return coinChange(change, n - 1) + coinChange(change - coinArr[n], n);
}

int HouseThief(int index = 0) {
	if (index >= (sizeof(House) / sizeof(House[0])))
		return 0;

	int steal = House[index] + HouseThief(index + 2);
	int skip = HouseThief(index + 1);

	return max(steal, skip);
}

int str_convert(const string& trgt, const string& orig, int Tidx = 0, int Oidx = 0) {	
	if (Tidx >= trgt.size())
		return orig.size() - Oidx;

	if (Oidx >= orig.size())
		return trgt.size() - Tidx;

	if (orig[Oidx] == trgt[Tidx])
		str_convert(trgt, orig, Tidx + 1, Oidx + 1);
	else {
		int insrt = 1 + str_convert(trgt, orig, Tidx, Oidx + 1);
		int rmv = 1 + str_convert(trgt, orig, Tidx + 1, Oidx);
		int rplc = 1 + str_convert(trgt, orig, Tidx + 1, Oidx + 1);

		return min({ rmv, insrt, rplc });
	}
}

int zero_one_knapsack(int capacity, int index = 0) {
	int profit1 = 0;
	
	if (capacity <= 0 || index >= n)
		return 0;
	else if (items[index].second <= capacity)
		profit1 = items[index].first + zero_one_knapsack(capacity - items[index].second, items, n, index + 1);
		
	int profit2 = zero_one_knapsack(capacity, items, n, index + 1);

	return max(profit1, profit2);
}
//----Custom LCS (Needs additional testing, but everything seems to work fine)----
int _LCS(const string& s1, const string& s2, int s1i = 0, int s2i = 0) { //Longest Common Subsequence
	if (s1i >= s1.size() || s2i >= s2.size())
		return 0;
	
	if (s1[s1i] == s2[s2i])
		return 1 + _LCS(s1, s2, s1i + 1, s2i + 1);
		
	int m1 = _LCS(s1, s2, s1i + 1, s2i);
	int m2 = _LCS(s1, s2, s1i, s2i + 1);

	return max(m1, m2);
	
}
//----Custom LPS (Needs additional testing, but everything seems to work fine)----
//Caution: bw in given argument is equal to s1 size so, s1[bw] = '\0', but it seems to work anyway.
int _LPS(const string& s1, int bw, int fw = 0) { //Longest Palindromic Subsequence
	if (fw >= s1.size() || bw < 0)
		return 0;

	if (s1[fw] == s1[bw])
		return 1 + _LPS(s1, bw - 1, fw + 1);

	int forward = _LPS(s1, bw, fw + 1);
	int backward = _LPS(s1, bw - 1, fw);

	return max(forward, backward);
}

int LCS(const string& s1, const string& s2, int s1i = 0, int s2i = 0) { //Longest Common Subsequence
	if (s1i >= s1.size() || s2i >= s2.size())
		return 0;

	int m1 = 0;
	if (s1[s1i] == s2[s2i])
		m1 = 1 + LCS(s1, s2, s1i + 1, s2i + 1);

	int m2 = LCS(s1, s2, s1i + 1, s2i);
	int m3 = LCS(s1, s2, s1i, s2i + 1);

	return max({ m1, m2, m3 });

}

int LPS(const string& s1, int bw, int fw = 0) { //Longest Palindromic Subsequence
	if (fw > bw)
		return 0;

	if (fw == bw)
		return 1;

	int bi = 0;
	if (s1[fw] == s1[bw])
		bi = 2 + LPS(s1, bw - 1, fw + 1);

	int forward = LPS(s1, bw, fw + 1);
	int backward = LPS(s1, bw - 1, fw);

	return max({ forward, backward, bi });
}

int LPs(const string& s1, int bw, int fw = 0) { //Longest Palindromic Substring
	if (fw >= s1.size() || bw < 0)
		return 0;

	int z = 0;
	if (s1[fw] == s1[bw]) {
		int remaining_lngth = bw - fw - 1;
		if (remaining_lngth == LPs(s1, bw - 1, fw + 1))
			z = remaining_lngth + 2;
	}
	int forward = LPs(s1, bw, fw + 1);
	int backward = LPs(s1, bw - 1, fw);

	return max({ forward, backward, z });
}

int minCost(int x = 5, int y = 5) { //Minimal cost to reach end of the array
	if (x <= 0 || y <= 0)
		return INT_MAX;
	
	if (x == 1 && y == 1)
		return Matrix[0][0];

	return min(minCost(x - 1, y), minCost(x, y - 1)) + Matrix[x - 1][y - 1];
}

int numOfWays(int cost, int x = 4, int y = 4) { //Number of ways to reach end of array with given cost
	if (x < 0 || y < 0 || cost < 0)
		return 0;
	
	if (x == 0 && y == 0)
		return ((cost - Matrix[0][0]) >= 0) ? 1 : 0;

	return numOfWays(cost - Matrix[x][y], x - 1, y) + numOfWays(cost - Matrix[x][y], x, y - 1);
}

int main(int argc, char** argv) {
	cout << HouseThief() << endl;
	
	cout << str_convert("tbres", "table") << endl;
	cout << str_convert("carch", "catch") << endl;
	cout << str_convert("zuka", "eka") << endl;
	
	cout << zero_one_knapsack(50) << endl;

	cout << LCS("zuka", "gio") << endl;

	cout << _LPS("ABCCBUA", 6) << endl;
	cout << _LPS("ABCYRCFBTUA", 10) << endl;
	cout << _LPS("A", 0) << endl;
	
	cout << minCost() << endl;
	
	cout << numOfWays(40) << endl;
}