#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;			

// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// Palindrome Partitioning
// Here we need to find minimum number of partitions we need to make in order to make all strings in all partitions palindrome
// so in worst case we make s.length() - 1 partitions as each character is palindrome
// We use MCM here as we need to try every value of k between i and j for partitioning

bool isPali(string x, int i, int j) {
	while(i < j) {
		if(x[i] != x[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int dp[501][501];
int solve(string x, int i, int j) {
	// if string becomes empty or it has single character we need 0 partitions
	if(i >= j)
		return 0;
	// if the string is already palindrome then also we need 0 partitions
	if(isPali(x, i, j))
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = INT_MAX;
	// till j - 1 as we are passing k + 1 so if we are at end position we cannot take k at end and then pass k + 1, j
	for(int k = i; k < j; k++) {
		//int temp = solve(x, i, k) + solve(x, k + 1, j) + 1; // as we are making one partition here
		// optimizing recursive calls here
		int left, right;
		if(dp[i][k] != -1)
			left = dp[i][k];
		else {
			left = solve(x, i, k);
			dp[i][k] = left;
		}
		if(dp[k + 1][j] != -1) 
			right = dp[k + 1][j];
		else {
			right = solve(x, k + 1, j);
			dp[k + 1][j] = right;
		}
		ans = min(ans, 1 + left + right);
	}
	return dp[i][j] = ans;
}

int32_t main() {
	string x;
	cin >> x;
	memset(dp, -1, sizeof dp);
	cout << solve(x, 0, x.length() - 1);
	return 0;
}
