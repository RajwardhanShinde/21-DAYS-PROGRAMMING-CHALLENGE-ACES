#include<iostream>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
// #define int long long int
using namespace std;
// int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	long long int x, y, a, b;
	cin >> x >> y >> a >> b;
	long long int exp = 0;
	if (a >= b && x < y) {
		cout << (y - x - 1) / b;
		return 0;
	}
	bool flag = false;
	while (x < y) {
		if (((double)x * a <= 2e18) && (x * a) < x + b) {
			x *= a;
		} else {
			flag = true;
			break;
		}
		if (x < y)
			++exp;
	}
	if (flag && x < y) {
		y--;
		cout << exp + ((y - x) / b);
	} else {
		cout << exp;
	}
	return 0;
}
