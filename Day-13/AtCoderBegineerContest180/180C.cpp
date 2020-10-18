#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	vector<int> res;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i)
				cout << i << endl;
			else {
				cout << i << endl;
				res.push_back(n / i);
			}
		}
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i] << endl;
	return 0;
}
