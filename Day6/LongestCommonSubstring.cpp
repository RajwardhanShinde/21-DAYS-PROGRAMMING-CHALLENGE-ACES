#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// https://practice.geeksforgeeks.org/problems/longest-common-substring/0
// Longest Common Substring
// We require continous equal characters as soon as we get not equal characters we make count = 0
//int lcs(string x, string y, int n, int m, int curr) {
	//if(n < 0 || m < 0)
		//return curr;
	//if(x[n] == y[m])
		//curr = lcs(x, y, n - 1, m - 1, curr + 1);
	//curr = max({curr, lcs(x, y, n - 1, m, 0), lcs(x, y, n, m - 1, 0)});
	//return curr;
//}


int32_t main() {
	string x, y;
	cin >> x >> y;
	int n = x.length(), m = y.length();
	//cout << lcs(x, y, n - 1, m - 1, 0);
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 0; j <= m; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = 0;
		}
	}
	int max_len = 0;
	for(int i = 1; i <= n; i++) {
		for(int  j = 1; j <= m; j++) {
			max_len = max(max_len, dp[i][j]);
		}
	}
	cout << max_len;
	return 0;
}
