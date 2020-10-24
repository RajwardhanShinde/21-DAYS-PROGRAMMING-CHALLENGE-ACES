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

// Maximum Path Sum from one leaf node to another
// same as maximum path sum but here both the end nodes need to be leaf nodes
int MaxPathSum(Tree *root, int& res) {
	if(!root)
		return 0; 
	
	int l = MaxPathSum(root->left, res);
	int r = MaxPathSum(root->right, res);
	
	// finding max from left and right
	int temp = max(l, r) + root->val;
	// if current node is not leaf then there is no choice so we store max l + r + root->val in result
	if(root->left && root->right) {
		res = max(res, l + r + root->val);
		// returning temp for further nodes
		return temp;
	}
	// otherwise we return data from left or right for which value exists
	return (root->left == NULL) ? r + root->val : l + root->val;
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
