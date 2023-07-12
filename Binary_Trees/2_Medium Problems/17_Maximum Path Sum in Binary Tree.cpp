// L17. Maximum Path Sum in Binary Tree 

// Approach- 3 steps - 
// #negative -> 0 sum
// #supply sum to upper nodes -> return root->data + max(leftSum, rightSum)
// #find max at a particular node -> max(maxSum, root->data+leftSum+rightSum)

// Method-1 : 
class Solution {
  private:
    int solve(Node* root, int &maxSum){
        if(root == NULL){
            return 0 ;
        }
        int leftSum = max(0, solve(root->left, maxSum)) ;
        int rightSum = max(0, solve(root->right, maxSum)) ;
        
        maxSum = max(maxSum, root->data+leftSum+rightSum) ;
        
        return root->data + max(leftSum, rightSum) ;
    }
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        if(root == NULL){
            return 0 ;
        }
        int maxSum = INT_MIN;
        
        solve(root, maxSum) ;
        return maxSum ;
    }
};

// Method-2 :
class Solution {
  private:
    int solve(Node* root, int &maxSum){
        if(root == NULL){
            return 0 ;
        }
        int leftSum = solve(root->left, maxSum) ;
        int rightSum = solve(root->right, maxSum) ;
        
        int temp = max(root->data, root->data + max(leftSum, rightSum)); //given to upper nodes
        int ans = max(temp, root->data + leftSum + rightSum) ;  
        
        maxSum = max(maxSum, ans) ;

        return temp ;
    }
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        if(root == NULL){
            return 0 ;
        }
        int maxSum = INT_MIN;

        solve(root, maxSum) ;
        return maxSum ;
    }
};