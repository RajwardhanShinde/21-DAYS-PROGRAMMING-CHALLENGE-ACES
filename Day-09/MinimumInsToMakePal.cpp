#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
// Minimum Insertion to make string palindrome
// we know that we can find current palindrome by finding lcs of current string and its reversed string 
// so we need to do some operation on remaining characters 
// example - aebcbda
// lcs - abcba here e and d are extra so need a pair for e and d so insertions = 2
// it is same as deletion to make string palindrome
int32_t main() {
	string x, y;
	cin >> x;
	y = x;
	reverse(y.begin(), y.end());
	int n = x.length(), m = n;
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = dp[0][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << n - dp[n][m];
	return 0;
}
