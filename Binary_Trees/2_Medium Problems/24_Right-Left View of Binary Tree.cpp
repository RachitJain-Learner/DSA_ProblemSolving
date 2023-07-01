// 24. Right/Left View of Binary Tree

/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};  */

//Function to return a list containing elements of left view of the binary tree.

void helper(Node *root, int lvl, vector<int>& ans){
    if(root == NULL)
        return ;
    
    if(ans.size() == lvl){
        ans.push_back(root->data) ;
    }
    helper(root->left, lvl+1, ans) ;
    helper(root->right, lvl+1, ans) ;
}
vector<int> leftView(Node *root)
{
   vector<int> ans ;

   helper(root, 0, ans) ;
   return ans ;
}