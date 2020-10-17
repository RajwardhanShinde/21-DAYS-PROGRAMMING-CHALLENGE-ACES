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
	int arr[n];
	int sum = 0, sumsq = 0, mxx = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mxx = max(abs(arr[i]), mxx);
		sum += abs(arr[i]);
		sumsq += abs(arr[i] * arr[i]);
	}
	cout << sum << endl;
	cout << fixed << setprecision(15) << sqrt(sumsq) << endl;
	cout << mxx << endl;
	return 0;
}

