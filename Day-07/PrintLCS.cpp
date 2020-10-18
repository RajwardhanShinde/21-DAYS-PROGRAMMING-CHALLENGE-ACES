#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// Printing Longest Common Subsequence
// We first find the dp matrix and start traversing from the end and check if x[i - 1] == y[j - 1] if it is
// then we take current char in our result otherwise we check for dp[i - 1][j] and dp[i][j - 1] values and 
// we move in the direction of maximum value and we continue this process until we reach i == 0 || j == 0 i.e null string
int32_t main() {
	string x, y;
	cin >> x >> y;
	int n = x.length(), m = y.length();
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
	int i = n, j = m;
	string res;
	while(i > 0 && j > 0) {
		if(x[i - 1] == y[j - 1]) {
			res += x[i - 1];
			i--;
			j--;
		} else {
			if(dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
