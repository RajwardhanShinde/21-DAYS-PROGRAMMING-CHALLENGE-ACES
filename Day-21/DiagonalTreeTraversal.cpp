vector<vector<int>> val(1001);
 void solve(Tree *root, int d) {
    if(!root)
        return;
    val[d].push_back(root->val);
    solve(root->left, d + 1);
    solve(root->right, d);
 }
 
vector<int> solve(Tree* root) {
    val.clear();
    for(int i = 0; i < 1001; i++)
        val[i].clear();
    solve(root, 0);
    vector<int> res;
    for(int i = 0; i < 1001; i++) {
        int sum = 0;
        bool flag = false;
        for(int j = 0; j < val[i].size(); j++) {
            flag = true;
            sum += val[i][j];
        }
        if(flag)
            res.push_back(sum);
    }
    return res;
}
