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
		for(int i = 0; i < n; i++) 
			cin >> arr[i];
		int max_ele = *max_element(arr, arr + n);
		int index = -1;
		for(int i = 0; i < n; i++) {
			if(arr[i] == max_ele) {
				if(i - 1 >= 0 && arr[i - 1] < arr[i]) {
					index = i + 1;
					break;
				}
				if(i < n - 1 && arr[i + 1] < arr[i]) {
					index = i + 1;
					break;
				}
			}
		}
		cout << index << endl;
	}
	return 0;
}
