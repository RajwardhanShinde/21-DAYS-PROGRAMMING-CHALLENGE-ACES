#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Minimum Number of insertion and deletion to convert string a to b
// ex - a = heap
// 		b = pea
// 		lcs of this string is ea
// 		apart from that we just need to delete remaining not used character from string a and add other characters from string b that are not present in a
// 		answer - 2 deletion(h, p) 1 insertion(p)

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
	int lcs = dp[n][m];
	int ans = n - lcs;
	ans += m - lcs;
	cout << ans;
	return 0;
}
