#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int wt[101], val[101];
//vector<vector<int>> dp; // we make dp for changing values here cap and n is changing
//int knapsack(int n, int cap) {
	//if(n == 0 || w == 0) // recursive functions base condition will be used for bottom ups initialization of matrix
		//return 0;
	//if(dp[n][cap] != -1)
		//return dp[n][cap];
	//int ans = knapsack(n - 1, cap); // we will do this same condition when current cap is less than the items weight
	//if(cap >= wt[n])
		//ans = max(ans, val[n] + knapsack(n - 1, cap - wt[n])); // we will use this condition when current cap can hold current items weight in bottom up
	//return dp[n][cap] = ans;
//}

int32_t main() { 
	int n, cap;	
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> wt[i];
	for(int i = 0; i < n; i++)
		cin >> val[i];
	cin >> cap;
	//dp.resize(n, vector<int>(cap + 1, -1));
	//cout << knapsack(n - 1, cap);
	int dp[n + 1][cap + 1];
	// i is current item and j is capacity
	// when there are 0 items or 0 capacity we can hold 0 profit
	
	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < cap + 1; j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0; // we are using wt[i - 1] as we have taken n + 1 as we use first row and first column just for initialisation and we elements map one more index in the matrix than in original array
				continue;
			}
 			if(j >= wt[i - 1]) {
				// here we will choose max of two choices either we can take or skip
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			} else {
				// just skip as it cannot hold current elements weight
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][cap] << endl;
	return 0;
}
