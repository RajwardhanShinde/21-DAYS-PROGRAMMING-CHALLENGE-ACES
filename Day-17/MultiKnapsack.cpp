int dp[251][251][251];
int n;
vector<int> w, val;
int knap(int cap, int count, int index) {
    if (count == 0 || cap == 0 || index < 0) return 0;
    if(dp[index][cap][count] != -1)
        return dp[index][cap][count];
    int ans = 0;
    ans = knap(cap, count, index - 1);
    if (cap - w[index] >= 0) {
        ans =max(ans, val[index] + knap(cap - w[index], count - 1, index - 1));
    }
    return dp[index][cap][count] = ans;
}

int solve(vector<int>& weights, vector<int>& values, int capacity, int count) {
    w = weights, val = values;
    int n = weights.size();
    memset(dp, -1, sizeof(dp));
    return knap(capacity, count, n - 1);
}
