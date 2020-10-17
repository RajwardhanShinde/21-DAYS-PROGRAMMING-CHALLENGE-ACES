#include<bits/stdc++.h>
#define fastio     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;        

int32_t main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        bitset<50> b1(a ^ b);
        cout << b1.count() << endl;
    }    
    return 0;
}
