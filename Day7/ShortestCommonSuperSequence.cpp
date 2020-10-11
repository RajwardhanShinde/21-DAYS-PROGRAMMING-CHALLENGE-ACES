#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
// Shortest Common SuperSequence
// we have to merge two strings and these two strings should appear in new merged string in sequence but we have to use minimum characters 
// ex - AGGTAB, GXTXAYB - AGGTXAYB - here we reduced string length from 13 to 9
int32_t main() {
	string x, y;
	cin >> x >> y;
	
	// My Own Solution
	int n = x.length(), m = y.length();
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = i;
	for(int j = 0; j <= m; j++)
		dp[0][j] = j;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = min({2 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]}); 
		}
	}
	cout << dp[n][m];
	
	// Another Easy Solution n + m - LCS as LCS is common can be used only once 
	//int dp[n + 1][m + 1];
	//for(int i = 0; i <= n; i++)
		//dp[i][0] = 0;
	//for(int j = 0; j <= m; j++)
		//dp[0][j] = 0;
	//for(int i = 1; i <= n; i++) {
		//for(int j = 1; j <= m; j++) {
			//if(x[i - 1] == y[j - 1])
				//dp[i][j] = 1 + dp[i - 1][j - 1];
			//else
				//dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		//}	
	//}
	//cout << n + m - dp[n][m];
	return 0;
}
