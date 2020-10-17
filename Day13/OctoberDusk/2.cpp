#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long int
using namespace std;
int mod = 1e9 + 7;		

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int arr[n];
		set<int> s;
		vector<int> res;
		for(int i = 0; i < n; i++) { 
			cin >> arr[i];
			if(s.find(arr[i]) == s.end())
				res.push_back(arr[i]);
			s.insert(arr[i]);
		}
		if(res.size() <= 1) {
			cout << -1 << endl;
			continue;
		}
		int count = 0;
		sort(res.begin(), res.end(), greater<int>());
		cout << res[1] << endl;
	}
	return 0;
}
