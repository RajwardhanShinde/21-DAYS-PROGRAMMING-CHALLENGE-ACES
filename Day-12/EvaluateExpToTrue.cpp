#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
// Evaluate the number of ways you can place brackets so that result of the expression is true
// we have 3 operators in input string &, |, ^ and T and F for indicating true and false 
// this is a MCM problem as we have to place parenthesis so we can place bracket from i to k - 1 and k + 1 to j and k should always remain on operator as between two brackets there should be operator so we increment k by 2
// ex - T ^ F & T here we have two ways to make it true ((T ^ F) & T) and (T ^ (F & T))
int dp[501][501][2];
int solve(string x, int i, int j, bool isTrue) {
	if(i > j)
		return false;
		
	// if there is single character then we check value of isTrue so if it is true and current character is T then we return true and same for false condition
	if(i == j) {
		if(isTrue)
			return x[i] == 'T';
		return x[i] == 'F';
	}
	
	if(dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];
	// as we are starting k from position 1 and moving by 2 position in each iteration
	int ans = 0;
	for(int k = i + 1; k < j; k = k + 2) {
		// now we are checking for number of true values on left and right, number of false values on left and right
		// example - like xor is true if one true could pair with some false so if false values are 4 and true values are 2 then there would 4 * 2 combinations
		// so it is important to check true as well as false values and then we would utilize them according to our current operator
		// we can optimize these recursive calls by using dp matrix
		int lt = solve(x, i, k - 1, true);
		int lf = solve(x, i, k - 1, false);
		int rt = solve(x, k + 1, j, true);
		int rf = solve(x, k + 1, j, false);
		
		if(x[k] == '&') {
			// so here we are checking currently we want true values combinations or false value combinations according to that we are generating different combinations that would make that value
			if(isTrue)
				ans += lt * rt;
			else 
				ans += (lt * rf) + (lf * rt) + (lf * rf);
		} else if(x[k] == '|') {
			if(isTrue)
				ans += (lt * rt) + (lf * rt) + (lt * rf);
			else
				ans += (lf * rf);
		} else {
			// for xor
			if(isTrue) 
				ans += (lt * rf) + (rt * lf);
			else
				ans += (lt * rt) + (lf * rf);
		}
	}
	return dp[i][j][isTrue] = ans;
}

int32_t main() {
	string x;
	cin >> x;
	memset(dp, -1, sizeof dp);
	cout << solve(x, 0, x.length() - 1, true);
	return 0;
}
