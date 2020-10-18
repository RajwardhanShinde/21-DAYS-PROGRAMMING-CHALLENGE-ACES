#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	


int mat[100001][4];
// int dp[100001][4];
//int Vac(int n, int last) {
	//if(n == 0)
		//return 0;
	//if(last > 0 && dp[n][last] != -1)
		//return dp[n][last];
	//int ans = INT_MIN;
	//for(int i = 1; i <= 3; i++) {
		//if(i != last)
			//ans = max(ans, mat[n - 1][i] + Vac(n - 1, i));
	//}
	//if(last > 0)
		//dp[n][last] = ans;
	//return ans;
//}

int32_t main() {
	int n;
	cin >> n;
	//memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= 3; j++)
			cin >> mat[i][j];
	int dp[n][4];
	dp[0][1] = mat[0][1];
	dp[0][2] = mat[0][2];
	dp[0][3] = mat[0][3];
	for(int i = 1; i < n; i++) {
		dp[i][1] = mat[i][1] + max(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] = mat[i][2] + max(dp[i - 1][1], dp[i - 1][3]);
		dp[i][3] = mat[i][3] + max(dp[i - 1][1], dp[i - 1][2]);
	}	
	cout << max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
	//cout << Vac(n, -1);
	return 0;
}
