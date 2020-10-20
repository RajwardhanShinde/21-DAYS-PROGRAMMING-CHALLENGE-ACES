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
		unordered_set<int> s;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
			s.insert(arr[i]);
		}
		if(s.size() == 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int root = arr[0];
		int index = -1;
		for(int i = 0; i < n; i++) {
			if(arr[i] != root) {
				cout << 1 << " " << i + 1 << endl;
				index = i + 1;
 			}
		}
		for(int i = 1; i < n; i++) {
			if(arr[i] == root) {
				cout << index << " " << i + 1 << endl;
			}
		}
	}
	return 0;
}
