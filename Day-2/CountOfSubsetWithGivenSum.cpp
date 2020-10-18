#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

int countOfSubset(int arr[], int n, int sum) {
	if(sum == 0)
		return 1;
	if(n == 0)
		return 0;
	if(arr[n - 1] > sum)
		return countOfSubset(arr, n - 1, sum);
	return countOfSubset(arr, n - 1, sum) + countOfSubset(arr, n - 1, sum - arr[n - 1]);
}

// works for non-zero elements if we have any zeros in our array then we can intialize first column with
// 2 ^ (no of zeros upto no of elements included at that point i.e i)

int32_t main() {
	int n;
	cin >> n;
	int arr[n], sum;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> sum;
	cout << countOfSubset(arr, n, sum) << endl;
	int dp[n + 1][sum + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for(int i = 1; i <= sum; i++)
		dp[0][i] = 0;
	// here we will just sum the two choices i.e if we take element or if we leave element as we 
	// want all counts that sum up to our given sum
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][sum];
}
