#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node
class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

// Preorder Traversal of Binary Tree

void solve(TreeNode* root, vector<int>& ans){
    if(root == NULL)    
        return ;

    ans.push_back(root->val) ;
    solve(root->left, ans) ;
    solve(root->right, ans) ; 
}
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;

    solve(root, ans) ;
    return ans ;
}


// Inorder Traversal of Binary Tree

void solve(TreeNode* root, vector<int>& ans){
    if(root == NULL)    
        return ;

    solve(root->left, ans) ;
    ans.push_back(root->val) ;
    solve(root->right, ans) ; 
}
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;

    solve(root, ans) ;
    return ans ;
}


// Postorder Traversal of Binary Tree

void solve(TreeNode* root, vector<int>& ans){
    if(root == NULL)    
        return ;

    solve(root->left, ans) ;
    solve(root->right, ans) ;
    ans.push_back(root->val) ;
}
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ans;

    solve(root, ans) ;
    return ans ;
}

