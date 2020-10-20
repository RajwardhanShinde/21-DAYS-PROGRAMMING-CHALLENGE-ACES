#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
	int t;
	cin >> t;
	//int x;
	string x;
	while(t--) {
		cin >> x;
		//int curr = 1, count = 1, dig = 1, reset = 1, ans = 1;
		string curr;
		int dig = 1, size = 1, count = 0;
		while(curr != x) {
			curr += '0' + dig;
			if(curr.length() == 5) {
				dig++;
				curr = '0' + dig;
			}
			count += (int)curr.length();
		}
		cout << count << endl;
	}
	return 0;
}
