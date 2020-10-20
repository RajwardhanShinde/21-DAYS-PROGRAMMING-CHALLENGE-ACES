#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int prev = -1;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i] == 1) {
				if(prev != -1)
					ans += i - prev - 1; 
				prev = i;
			}
		}
		cout << ans << endl;
	}	
	return 0;
}
