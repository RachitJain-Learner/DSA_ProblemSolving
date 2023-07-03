// 34. Construct a Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd, unordered_map<int, int>& inMap){
        if(inStart > inEnd || preStart > preEnd)
            return NULL ;
            
        int rootNode = preorder[preStart] ;
        TreeNode* root = new TreeNode(rootNode);
        
        int rootIndex = inMap[rootNode] ;
        int num = rootIndex - inStart ;

        root->left = constructTree(preorder, inorder, inStart, rootIndex-1, preStart+1, preStart+num, inMap) ;

        root->right = constructTree(preorder, inorder, rootIndex+1, inEnd, preStart+num+1, preEnd, inMap) ;
        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() ;
        
        unordered_map<int, int> inMap ;
        for(int i=0; i<n ; i++){
            inMap[inorder[i]] = i ;
        }
        return constructTree(preorder, inorder, 0, n-1, 0, n-1, inMap) ;
    }
};