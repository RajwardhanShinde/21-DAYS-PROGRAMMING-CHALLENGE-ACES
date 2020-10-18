#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// https://practice.geeksforgeeks.org/problems/rod-cutting/0/
// just another version of unbounded knapsack 
// we have to cut rod into pieces just that we get maximum profit
int32_t main() {
    int t;
    cin >> t;
    while(t--) {
		int n;
		cin >> n;
		int price[n], length[n];
		for(int i = 0; i < n; i++) {
			cin >> price[i];
			length[i] = i + 1;
		}
		int dp[n + 1][n + 1];
		for(int i = 0; i <= n; i++)
			dp[i][0] = 0, dp[0][i] = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(j >= length[i - 1])
					dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - length[i - 1]]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][n] << endl;
    }
	return 0;
}
