#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;			

// https://leetcode.com/problems/burst-balloons/
// Matrix Chain Multiplication
// Finding minimum cost to multiply matrix
// cost is number of multiplications
// so we have array of matrix dimensions so we have choose where to put brackets like for matrices a1, a2, a3, a4 -  (a1 * a2) * (a3 * a4) or (a1 * a2 * a3) * (a4)
// we start at i = 1 as arr[i - 1] * arr[i] = one matrix dimensions
// we are choosing a value for k between i to j - 1 and checking which value gives us the minimum cost 
// cost for matrix multiplication is 
// ex - a * b - dimension for matrix one
// c * d - dimension for second matrix
// b == c for matrix multiplication they need to be equal so total cost - a * b * d  taking equal value just once
// this is what we are using below arr[i - 1] * arr[k] * arr[j]

int dp[101][101];
int solve(int arr[], int i, int j) {
	if(i >= j)
		return 0;
	
	if(dp[i][j] != -1)
		return dp[i][j];
	
	int cost = INT_MAX;
	for(int k = i; k < j; k++) {
		int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
		cost = min(temp, cost);
	}
	return dp[i][j] = cost;
}

int32_t main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve(arr, 1, n - 1);
	return 0;
}
