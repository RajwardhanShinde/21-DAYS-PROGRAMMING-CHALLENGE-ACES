bool flag;
void preorder(Tree *root)  {
    if(!root)
        return;
    if(root->left || root->right) {
        int sum = 0;
        if(root->left)
            sum += root->left->val;
        if(root->right)
            sum += root->right->val;
        if(sum != root->val) {
            flag = false;
            return;
        }
    }
    preorder(root->left);
    preorder(root->right);
}
bool solve(Tree* root) {
    flag = true;
    preorder(root);
    return flag;
}
