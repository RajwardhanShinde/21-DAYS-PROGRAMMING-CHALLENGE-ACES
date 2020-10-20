#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
// Egg Dropping Problem
// We are given e eggs and f floors and we have to return the minimum number of attempts to find the lowest floor from which egg doesnt break
// so we have f floors from 1 to f and we have e eggs so if we choose a floor and throw egg from it and if it breaks then we need to check from lower floor and if doesnt break then we need to check upper floors
// we have to find the worst case where we utilize maximum attempts example - when we have just 1 egg then we have to check all floors as we cannot take risk to break the egg 
int dp[11][51];
int solve(int e, int f) {
	if(f == 0 || f == 1)
		return f;
	if(e == 1)
		return f;
	if(dp[e][f] != -1)
		return dp[e][f];
	int ans = INT_MAX;
	for(int k = 1; k <= f; k++) {
		// we have to two cases either egg breaks or it doesnt and we have to find maximum attempts i.e worst case
		int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
		// finding minimum attempts of worst cases
		ans = min(temp, ans);
	}
	return dp[e][f] = ans;
}

int32_t main() {
	int e, f;
	cin >> e >> f;
	memset(dp, -1, sizeof dp);
	cout << solve(e, f);
	return 0;
}
