#include<bits/stdc++.h>
using namespace std;

void tester() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
//memoization
int solve(vector<int>arr, int n, vector<int>&dp) {
	int left = INT_MAX;
	int right = INT_MAX;
	if (n == 0)return 0;
	if (dp[n] != -1)return dp[n];
	left = solve(arr, n - 1, dp) + abs(arr[n] - arr[n - 1]);
	if (n > 1) {
		right = solve(arr, n - 2, dp) + abs(arr[n] - arr[n - 2]);
	}
	return dp[n] = min(right, left);
}


int main() {
	tester();

	vector<int>arr = {10, 20, 30, 10, 50, 10, 20, 30, 55, 56};
	int n = arr.size();
	vector<int>arr2 = {30, 10, 60, 10, 60, 50, 20, 50, 34, 12, 54, 76, 78};
	int m = arr2.size();
	vector<int>dp1(n + 1, -1);
	vector<int>dp2(m + 1, -1);
	cout << solve(arr, n - 1 , dp1) << endl;
	cout << solve(arr2, m - 1 , dp2) << endl;
	//tabulation
	vector<int>arr3 = {10, 20, 30, 10, 50, 10, 20, 30, 55, 56};
	int o = arr.size();
	vector<int>dynap( o + 1, -1);
	dynap[0] = 0;
	for (int i = 1; i < o; i++) {
		int firstss = dynap[i - 1] + abs(arr3[i] - arr3[i - 1]);
		int secondss = INT_MAX;
		if (i > 1)
			secondss = dynap[i - 2] + abs(arr3[i] - arr3[i - 2]);
		dynap[i] = min(firstss, secondss);

	}
	cout << dynap[o - 1];
}
