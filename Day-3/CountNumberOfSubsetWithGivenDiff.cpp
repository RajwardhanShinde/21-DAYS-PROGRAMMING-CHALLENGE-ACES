#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

//   sum1 + sum2 = array_sum
// + sum1 - sum2 = diff
// ------------------------
//   2sum1 = array_sum + diff
// 	  sum1 = array_sum + diff
//			----------------
//					2

int32_t main() {
	// we just need to find the number of subsets with sum as sum1
	int n, diff;
	cin >> n;
	int arr[n], sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> diff;
	int sum1 = (sum + diff) / 2;
	int dp[n + 1][sum1 + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for(int j = 1; j <= sum1; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum1; j++) {
			if(j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][sum1]; 
	return 0;
}
