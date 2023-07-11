// L32. Count total Nodes in a COMPLETE Binary Tree | O(Log^2 N) Approach 

// Method-1 : Finding height recursively
class Solution {
  private:
    int leftHeight(Node* root){
        if(root == NULL){
            return 0 ;
        }
        return 1 + leftHeight(root->left) ;
    }
    int rightHeight(Node* root){
        if(root == NULL){
            return 0 ;
        }
        return 1 + rightHeight(root->right) ;
    }
  public:
    int countNodes(Node* root) {
        if(root == NULL)    
            return 0 ;
        
        int lh = leftHeight(root) ;
        int rh = rightHeight(root) ;
        
        if(lh == rh)
            return (1 << lh) -1 ;
        
        return 1 + countNodes(root->left) + countNodes(root->right) ;
    }
};

// Method-2 : Finding left and right height iteratively 

class Solution {
  private:
    int leftHeight(TreeNode* node){
        int ans = 0 ;
        while(node){
            ans++ ;
            node = node->left ;
        }
        return ans ;
    }
    int rightHeight(TreeNode* node){
        int ans = 0 ;
        while(node){
            ans++ ;
            node = node->right ;
        }
        return ans ;
    }
  public:
    int countNodes(TreeNode* root) {
        if(root == NULL)    
            return 0 ;
        
        int lh = leftHeight(root) ;
        int rh = rightHeight(root) ;
        
        if(lh == rh)
            return (1 << lh) -1 ;
        
        return 1 + countNodes(root->left) + countNodes(root->right) ;
    }
};