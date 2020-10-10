#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// https://leetcode.com/problems/longest-common-subsequence/
// Find Longest Common Subsequence from 2 strings
// Top Down Approach
//int dp[1001][1001];
//int lcs(string x, string y, int n, int m) {
	//if(n < 0 || m < 0)
		//return 0;
	//if(dp[n][m] != -1)
		//return dp[n][m];
	//// if we found common character we add it to our lcs length
	//if(x[n] == y[m]) 
		//return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
	//// otherwise we find the string from n - 1 or m - 1 which gives us maximum lcs length
	//return dp[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1)); 
//}

int32_t main() {
	string x, y;
	cin >> x >> y;
	int n = x.length(), m = y.length();
	//memset(dp, -1, sizeof dp);
	//cout << lcs(x, y, n - 1, m - 1);
	
	//Bottom Up Approach
	int dp[n + 1][m + 1];
	// when length of one of strings is 0 then lcs is 0
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 0; j <= m; j++)
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
