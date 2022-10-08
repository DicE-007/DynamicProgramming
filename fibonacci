#include<bits/stdc++.h>
using namespace std;

void tester() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int fibdp(int n , vector<int>&arr) {
	if (n <= 1) {
		return n;
	}
	if (arr[n] != -1) return arr[n];
	return arr[n] = fibdp(n - 1, arr) + fibdp(n - 2, arr);
}

int main() {
	tester();
	int n; cin >> n;
	vector<int>dp(n + 1, -1);
	cout << fibdp(n, dp) << endl; //tc = on sc = on+on(dp size+ rec stack)
	//tabulation
	int prev2 = 0;
	int prev1 = 1;
	for (int i = 2; i <= n; i++) {
		int cur = prev1 + prev2;
		prev2 = prev1;
		prev1 = cur;
	}
	cout << prev1; // tc = on sc =on

}
