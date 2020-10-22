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

// Diameter of binary tree
// diameter of tree is longest path from one node to any other node in tree
int diameter(Tree *root, int &res) {
	// if root is null we dont have any further nodes to traverse
	if(!root)
		return 0;
	// calculating number of nodes on left and right of current node and adding one for each node
	int l = diameter(root->left, res);
	int r = diameter(root->right, res);
	// taking max of left and right nodes
	int temp = max(l, r) + 1;
	// storing the longest path in res (l + r + 1)
	res = max(l + r + 1, res);
	return temp;
}

int32_t main() {
	Tree *root = new Tree(10);
	root->left = new Tree(5);
	root->right = new Tree(15);
	root->right->right = new Tree(20);
	int res = INT_MIN;
	diameter(root, res);
	cout << res << endl;
	return 0;
}
