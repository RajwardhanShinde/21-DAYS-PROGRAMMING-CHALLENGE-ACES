#include<bits/stdc++.h>
#define fastio     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;        

int32_t main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        char arr[n];
        // int count = 0;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) { 
            cin >> arr[i];
            if(arr[i] == 'Y')
                nums[i] = 1;
            else
                nums[i] = -1;
        }
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];
        int currentStart = 0, maxStart = 0, maxEnd = 0;

        for(int i = 1; i < n; i++) {
          if(maxEndingHere + nums[i] < nums[i]) {
            maxEndingHere = nums[i];
            currentStart = i;
          } else {
            maxEndingHere = maxEndingHere + nums[i];
          }

          if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            maxStart = currentStart;
            maxEnd = i;
          }
        }
        int count = 0;
        for(int i = maxStart; i <= maxEnd; i++) {
            if(arr[i] == 'Y')
                count++;
        }
        for(int i = 0; i < maxStart; i++) {
            if(arr[i] == 'X')
                count++;
        }
        for(int i = maxEnd; i < n; i++) {
            if(arr[i] == 'X')
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
