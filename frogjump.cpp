#include<bits/stdc++.h>
using namespace std;

void tester() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
//memoization
int helper(vector<int>&arr, vector<int>&dp, int n) {
	if (n == 0) {
		return 0;
	}
	if (dp[n] != -1)return dp[n];
	int j1 = helper(arr, dp, n - 1) + abs(arr[n] - arr[n - 1]);
	int j2 = INT_MAX;
	if (n > 1)
		j2 = helper(arr, dp, n - 2) + abs(arr[n] - arr[n - 2]);
	return dp[n] = min(j1, j2);
}
//tabulation
int helper2(vector<int>&arr, vector<int>&dp, int n) {
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		int j1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
		int j2 = INT_MAX;
		if (i > 1) {
			j2 = dp[n - 2] + abs(arr[i] - arr[i - 2]);
		}
		dp[i] = min(j1, j2);
	}
	return dp[n - 1];
}
//space
int helper3(vector<int>&arr, int n) {
	int prev = 0;
	int prev2 = 0;
	for (int i = 1; i < n; i++) {
		int j1 = prev + abs(arr[i] - arr[i - 1]);
		int j2 = INT_MAX;
		if (i > 1)
			j2 = prev2 + abs(arr[i] + arr[i - 2]);
		int cur = min(j1, j2);
		prev2 = prev;
		prev = cur;
	}
	return prev;
}
int main() {
	tester();
	int n; cin >> n;
	vector<int>stair(n);
	vector<int>dp(n + 1, -1);
	vector<int>dp2(n + 1, -1);
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}
	cout << helper(stair, dp, n) << endl;
	cout << helper2(stair, dp2, n ) << endl;
	cout << helper3(stair, n) << endl;
}
