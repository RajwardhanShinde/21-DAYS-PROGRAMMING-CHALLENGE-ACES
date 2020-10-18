#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	
	
// https://practice.geeksforgeeks.org/problems/coin-change2448/1
// In Coin Change we have coin array and we have to select some coins that sum up to a value
// and we can use multiple coins of one type so it is unbounded knapsack problem
int32_t main() {
	int n;
	cin >> n;
	int coin[n];
	for(int i = 0; i < n; i++)
		cin >> coin[i];
	int sum;
	cin >> sum;
	int dp[n + 1][sum + 1];
	// we can make 0 sum by taking no coins so the ways are 1
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	// we cannot make any sets of coins when we have 0 coins
	for(int j = 1; j <= sum; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			// as we want number of ways and we dont want any maximum or minimum value we add up all the ways to reach sum
			if(j >= coin[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}	
	cout << dp[n][sum];
	return 0;
}
