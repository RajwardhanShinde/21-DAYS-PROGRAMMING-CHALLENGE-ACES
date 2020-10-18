#include<bits/stdc++.h>
#define fastio     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;        

int32_t main() {
	int tc;
	cin >> tc;
	string s;
	for(int t = 1; t <= tc; t++) {
		cin >> s;
		int kick = 0, n = s.length();
		string k = "KICK", st = "START";
		int i = 0, count = 0;
		while(i < n) {
			if(s[i] == 'K' && i + k.length() - 1 < n && s.substr(i, k.length()) == k) {
				//cout << s.substr(i, k.length()) << endl;
				kick++;
			}
			if(kick && s[i] == 'S' && i + st.length() - 1 < n && s.substr(i, st.length()) == st) {
				count += kick;
			}
			i++;
		}
		cout << "Case #" << t << ": " << count << endl;
	}
	return 0;
}
