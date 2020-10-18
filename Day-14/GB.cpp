#include<bits/stdc++.h>
#define fastio     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;        
int mat[1001][1001];
bool vis[1001][1001];

int dfs(int i, int j, int n) {
	if(i <= 0 || j <= 0 || i > n || j > n || vis[i][j])
		return 0;
	vis[i][j] = true;
	int ans = 0;
	ans = mat[i][j] + dfs(i + 1, j + 1, n);
	ans = max(mat[i][j] + dfs(i - 1, j - 1, n), ans);
	return ans;
}

int32_t main() {
	int tc;
	cin >> tc;
	for(int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> mat[i][j];
			}
		}
		
		memset(vis, false, sizeof vis);
		int max_i = 0, max_j = 0, max_val = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(!vis[i][j]) {
					int val = dfs(i, j, n);
					if(val > max_val) {
						//max_i = i;
						//max_j = j;
						max_val = val;
					}
				}
			}
		}
		cout << "Case #" << t << ": " << max_val << endl;
	}
	return 0;
}
