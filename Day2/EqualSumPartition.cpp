#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	

bool equalPartition(int arr[], int n, int sum) {
	if(sum == 0)
		return true;
	if(n == 0)
		return false;
	if(arr[n - 1] > sum)
		return equalPartition(arr, n - 1, sum);
		
	return equalPartition(arr, n - 1, sum) || equalPartition(arr, n - 1, sum - arr[n - 1]);
}

int32_t main() {
	int n;
	cin >> n;
	int arr[n];
	int sum = 0;
	// we have to divide array into two equal sum partitions
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	// array can be divided if sum is even
	if(sum & 1) {
		cout << "NO";
		return 0;
	}
	// we will just find one partition of sum /= 2 if we find it then remaining elements 
	// will automatically sum to sum /= 2
	sum /= 2;
	//cout << equalPartition(arr, n, sum);
	int dp[n + 1][sum + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = true;
	for(int i = 1; i <= sum; i++)
		dp[0][i] = false;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}	
	if(equalPartition(arr, n, sum))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
