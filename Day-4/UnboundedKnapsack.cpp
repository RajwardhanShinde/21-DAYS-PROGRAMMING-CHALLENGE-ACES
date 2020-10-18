#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// Unbounded Knapsack
// we can take many instances of one item in the array
// unlike 01 knapsack where we can just take or leave that item and go to next index
// here we move from an index if we no more can take any instances of that item
int32_t main() {
	int n;
	cin >> n;
	int wt[n], val[n], cap;
	for(int i = 0; i < n; i++)
		cin >> wt[i];
	for(int i = 0; i < n; i++)
		cin >> val[i];
	cin >> cap;
	int dp[n + 1][cap + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 1; j <= cap; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= cap; j++) {
			if(j >= wt[i - 1])
				dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
			else
				dp[i][j] = dp[i - 1][j];
		} 
	}
	cout << dp[n][cap];	
	return 0;
}
