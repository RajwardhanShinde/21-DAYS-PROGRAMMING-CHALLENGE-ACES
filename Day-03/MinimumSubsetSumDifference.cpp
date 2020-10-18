#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

int32_t main() {
	int n;
	cin >> n;
	int arr[n];
	// here we dont save given sum here we have to find s1 and s2 such that their abs diff is min 
	// so we can just find one partition s1 and other we can get by sum - s1 so total = (sum - s1) - s1 which is sum - 2 * s1
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	bool dp[n + 1][sum + 1];
	// so here we are finding all of the sums in range 0 to sum such that it gives minimum abs diff 
	// so we can find all the sums of subset by using subset sum and we will use all elements in last row for which value is true means there exist a pair which sums upto those values
	for(int i = 0; i <= n; i++)
		dp[i][0] = true;
	for(int j = 1; j <= sum; j++)
		dp[0][j] = false;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j >= arr[i - 1]) 
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	// we will always keep value of s1 small so we would only take first half true values in last row which will satisfy as formula sum - 2 * s1;
	// so the last value before half of the last row will be answer as it would give min diff
	int s1 = 0;
	for(int i = 0; i <= sum / 2; i++)
		if(dp[n][i])
			s1 = i;
	cout << sum - 2 * s1;
	return 0;
}
