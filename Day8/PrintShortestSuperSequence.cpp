#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;		

// https://leetcode.com/problems/shortest-common-supersequence/	
// Printing SCS
// we find dp matrix for lcs as we just write lcs once in super sequence 
// then while adding characters according to dp matrix of lcs we add equal characters once and we also add current character before moving to maximum value in dp matrix
// for example if we move towards dp[i - 1][j] then we first add x[i -1] then we move similarly for dp[i][j - 1]
// at the end if i == 0 || j == 0 we stop 
// but we need to add all characters from both string so we need to make sure both i == 0 && j == 0 so we need two more while loops
int32_t main() {
	string x, y;
	cin >> x >> y;
	int n = x.length(), m = y.length();
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for(int j = 1; j <= m; j++)
		dp[0][j] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}	
	int i = n, j = m;
	string res;
	while(i > 0 && j > 0) {
		if(x[i - 1] == y[j - 1]) {
			res += x[i - 1];
			i--;
			j--;
		}
		else  {
			if(dp[i - 1][j] >= dp[i][j - 1])  {
				res += x[i - 1];
				i--;
			} else {
				res += y[j - 1];	
				j--;
			}
		}
	}
	// adding remaining characters
    while(i > 0)
       res += x[i - 1], i--;
    while(j > 0)
       res += y[j - 1], j--;
       
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
