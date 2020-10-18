#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int frog(int arr[], int n) {
	if(n == 0)
		return 0;
	int ans = abs(arr[n] - arr[n - 1]) + frog(arr, n - 1);
	if(n - 2 >= 0)
		ans = min(ans, abs(arr[n] - arr[n - 2]) + frog(arr, n - 2));
	return ans;
}

int32_t main() {
	fastio;
	
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	//cout << frog(arr, n - 1);
	int dp[n] = {0};
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int one = abs(arr[i - 1] - arr[i]) + dp[i - 1];
		int two = INT_MAX;
		if(i - 2 >= 0)
			two = abs(arr[i - 2] - arr[i]) + dp[i - 2];
		dp[i] = min(one, two);
	}
	cout << dp[n - 1];
	return 0;
}
