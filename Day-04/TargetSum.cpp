#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

//  https://leetcode.com/problems/target-sum/
//   sum1 + sum2 = array_sum
// + sum1 - sum2 = diff
// ------------------------
//   2sum1 = array_sum + diff
// 	  sum1 = array_sum + diff
//			----------------
//					2

// same as count number of subset with given difference 
// just instead of difference we have been given sum and we need to assign + or - to all array elements to get that sum
int32_t main() {
	int n;
	cin >> n;
	int arr[n];
	int count = 0, sum = 0, target;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		// for handling 0 array values as they dont add up or subtract anything but can be added in subsets
		if(arr[i] == 0)
			count++;
	}
	cin >> target;
	if(target > sum || (target + sum) & 1) { 
		cout << 0;
		return 0;
	}
	int s1 = (sum + target) / 2;
	int dp[n + 1][s1 + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for(int j = 1; j <= s1; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= s1; j++) {
			// ignoring 0 values
			if(arr[i - 1] == 0)
				dp[i][j] = dp[i - 1][j];
			else if(j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << pow(2, count) * dp[n][s1];
	return 0;
}
