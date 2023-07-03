// 35. Construct the Binary Tree from Postorder and Inorder Traversal 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inMap){
        if(inStart > inEnd || postStart > postEnd)
            return NULL ;

        int rootNode = postorder[postEnd] ;
        TreeNode* root = new TreeNode(rootNode) ;

        int rootIndex = inMap[rootNode] ;
        int num = rootIndex - inStart ;

        root->left = constructTree(inorder, postorder, inStart, rootIndex-1, postStart, postStart+num-1, inMap) ;
        root->right = constructTree(inorder, postorder, rootIndex+1, inEnd, postStart+num, postEnd-1, inMap) ;
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ;
        
        unordered_map<int, int> inMap ;
        for(int i=0 ; i<n ; i++){
            inMap[inorder[i]] = i ;
        }
        return constructTree(inorder, postorder, 0, n-1, 0, n-1, inMap) ;
    }
};