#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

// https://leetcode.com/problems/coin-change/
// Minimum number of coins to make the sum
int32_t main() {
	int n;
	cin >> n;
	int arr[n], sum;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> sum;
	int dp[n + 1][sum + 1];
	
	// to make 0 sum we need 0 elements
	for(int i = 1; i <= n; i++)
		dp[i][0] = 0;
	
	// when we have 0 elements we need infinite elements to make the sum
	for(int j = 0; j <= sum; j++)
		dp[0][j] = INT_MAX - 1; // to avoid overflow 
		
	// for this question we need to initialize second row also 
	// in second row we have only one element i.e arr[0] here we will put INT_MAX for sums which are not divisible by arr[0] and sum / arr[0] for other columns
	for(int j = 1; j <= sum; j++) {
		if(j % arr[0] == 0)
			dp[1][j] = j / arr[0];
		else
			dp[1][j] = INT_MAX - 1;
	}
	
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			// as we are adding one coin of a new value so we have 1 + dp[i][j - arr[i - 1]]
			if(j >= arr[i - 1])
				dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - arr[i - 1]]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][sum] == INT_MAX - 1 ? -1 : dp[n][sum];
	return 0;
}	
