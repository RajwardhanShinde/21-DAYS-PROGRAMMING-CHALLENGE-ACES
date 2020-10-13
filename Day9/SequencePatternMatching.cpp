#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// Find one whole string in another string
// Here we can find lcs of two strings and see if it is equal to minimum length string
// as one whole string should be present then lcs should be equal to string length
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
				dp[i][j] =  1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	if(dp[n][m] == min(n, m))
		cout << "True";
	else
		cout << "False";
	return 0;
}
