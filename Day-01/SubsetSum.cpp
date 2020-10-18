#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

bool hasSubset(int arr[], int n, int sum) {
	if(sum == 0)
		return true;
	if(n == 0)
		return false;
	if(arr[n - 1] > sum)
		hasSubset(arr, n - 1, sum);
	return hasSubset(arr, n - 1, sum) || hasSubset(arr, n - 1, sum - arr[n - 1]);
}

int32_t main() {
	fastio;
	
	int n;
	cin >> n;
	int arr[n], sum;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> sum;
	//cout << hasSubset(arr, n, sum);
	bool dp[n + 1][sum + 1];
	// when we have sum = 0 then we can make empty subsets i.e initialize with true 
	// when we have some sum and 0 elements we cannot make any subsets i.e initialize with false
	for(int i = 0; i <= n; i++)
		dp[i][0] = true;
		
	for(int j = 1; j <= sum; j++)
		dp[0][j] = false;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j >= arr[i - 1]) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	if(dp[n][sum])
		cout << "True";
	else
		cout << "False";
	return 0;
}
