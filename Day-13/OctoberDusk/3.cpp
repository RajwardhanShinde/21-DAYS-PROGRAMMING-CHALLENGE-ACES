#include<bits/stdc++.h>
#define fastio     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;        

int32_t main() {
    string a, b, c;
    cin >> a >> b >> c;
    unordered_map<char, int> mp;
    mp['S'] = 0, mp['R'] = 0, mp['A'] = 0;
    if(a[1] == '>') {
        mp[a[0]]++;
    } else {
        mp[a[2]]++;
    }
    if(b[1] == '>') {
        mp[b[0]]++;
    } else {
        mp[b[2]]++;
    }
    if(c[1] == '>') {
        mp[c[0]]++;
    } else {
        mp[c[2]]++;
    }
    vector<pair<int, char>> v;
    for(auto it : mp) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < 3; i++) {
        if(v[i].first == v[i - 1].first) {
            cout << "Impossible";
            return 0;
        }
    }
    for(int i = 0; i < 3; i++)
        cout << v[i].second;
    return 0;
}
