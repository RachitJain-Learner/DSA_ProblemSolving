// 27. Lowest Common Ancestor in Binary Tree 

// Coding Ninjas --> return -1 at NULL

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL){
        return -1 ;
    }
    
    if(root->data == x || root->data == y){
        return root->data ;
    }
    
    int left = lowestCommonAncestor(root->left, x, y) ;
    int right = lowestCommonAncestor(root->right, x, y) ;

    if(left == -1){
        return right ;
    }
    else if(right == -1){
        return left ;
    }
    else{
        return root->data ;
    }
}

// Leetcode Solution

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root ;

        if(root == p || root == q){
            return root ;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == NULL){
            return right ;
        }
        else if(right == NULL){
            return left ;
        }
        else
            return root ;
    }
};