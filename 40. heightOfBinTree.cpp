/*
Given a binary tree, find its height.

TC: O(N)  SC: O(1)
*/
int height(struct Node* root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}