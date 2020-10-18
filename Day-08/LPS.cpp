#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0, https://leetcode.com/problems/longest-palindromic-subsequence/
// Longest Palindromic Subsequence
// we can do this by finding LCS of two strings one string given in input and its reversed string
// as it should be palindromic longest subsequence it will match in both strings
int32_t main() {
	string x, y;
	cin >> x;
	int n = x.length(), m = n;
	y = x;
	reverse(y.begin(), y.end());
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 1; j <= m; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
	return 0;
}
