#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

int frog(int arr[], int n, int k) {
	if(n == 0)
		return 0;
	int one = abs(arr[n] - arr[n - 1]) + frog(arr, n - 1, k);
	for(int i = 2; i <= k; i++) 
		if(n - i >= 0) 
			one = min(one, abs(arr[n] - arr[n - i]) + frog(arr, n - i, k));
	return one;
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	//cout << frog(arr, n - 1, k);
	// as we have to calculate cost till n - 1 without including n
	int dp[n];
	memset(dp, INT_MAX, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i < n; i++) {
		int one = abs(arr[i] - arr[i - 1]) + dp[i - 1];
		for(int j = 2; j <= k; j++) {
			if(i - j >= 0)
				one = min(one, abs(arr[i - j] - arr[i]) + dp[i - j]);
		}
		dp[i] = one;
	}
	cout << dp[n - 1];
	return 0;
}

