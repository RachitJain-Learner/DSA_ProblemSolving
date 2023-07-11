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

// Count all nodes(whether present or not) between two corner 
// non nodes at a level


#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)    
            return 0 ;
        
        queue<pair<TreeNode*, int>> q ;
        q.push({root, 0});
        int ans = 0 ;

        while(!q.empty()){
            int size = q.size() ;
            int minIndex = q.front().second ;
            int first, last ;

            for(int i=0 ; i<size ; i++){
                auto node = q.front().first ;
                int ind = q.front().second-minIndex ;
                q.pop() ;

                if(i == 0) first = ind ;
                if(i == size-1) last = ind ;   

                if(node->left)
                    q.push({node->left, (ll)2*ind+1});  //typecasting into long long
                if(node->right)
                    q.push({node->right, (ll)2*ind+2});
            }
            ans = max(ans, last-first+1) ;
        }
        return ans ;
    }
};