#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
// Longest Repeating Subsequence
// Here we have just one string we have to finds its longest repeating subsequence
// for example - AXXXY
// we can take X X on index0 and index1 in one subsequence
// we can take X X on index1 and index2 in another subsequence
// example - AABCABB
// AB is lcs now we can choose different index for A and B and make 4 subsequence in total

int32_t main() {
	string x, y;
	cin >> x;
	y = x;
	int n = x.length(), m = n;
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0, dp[0][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1] && i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[n][m];
	return 0;
}	
