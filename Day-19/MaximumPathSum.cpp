#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;	
 
struct Tree {
	int val;
	Tree *left, *right;
	Tree(int data) {
		val = data;
		left = NULL, right = NULL;
	}
};

// Maximum Path Sum from any node to any node
// so if some nodes are adding negative values to our sum we exclude them and take sum of remaining path so starting or ending doesnt have to be leaf node
// so the idea is same as diameter of tree just we can start from any node so either we can take max(l, r) + root->val or root->val if max(l, r) gives us negative value then we can exclude it
// ans would be l + r + root->val
int MaxPathSum(Tree *root, int& res) {
	if(!root)
		return 0;
	int l = MaxPathSum(root->left, res);
	int r = MaxPathSum(root->right, res);
	// temp stores maximum path out of left, right or itself so that it can pass it to next node
	int temp = max(max(l, r) + root->val, root->val);
	// ans store maximum sum value from temp and l + r + root->val
	int ans = max(temp, l + r + root->val);
	// res stores overall max
	res = max(ans, res);
	return temp;
}

int32_t main() {
	Tree *root = new Tree(10);
	root->left = new Tree(5);
	root->right = new Tree(15);
	root->right->right = new Tree(20);
	root->left->right = new Tree(-10);
	root->left->left = new Tree(-5);
	int res = INT_MIN;
	MaxPathSum(root, res);
	cout << res << endl;
	return 0;
}
