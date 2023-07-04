// 26. Print Root to Node Path in Binary Tree - CodeStudio



// Similar GFG - Print All Root to Leaf Path in Binary Tree

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void possiblePaths(Node* root, vector<int>& temp, vector<vector<int>>& ans){
    
    temp.push_back(root->data) ;

    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp) ;
    }
    if(root->left)  
        possiblePaths(root->left, temp, ans);
    if(root->right) 
        possiblePaths(root->right, temp, ans);

    temp.pop_back() ;
}
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans ;
    if(root == NULL)    return ans ;
    
    vector<int> temp ;
    possiblePaths(root, temp, ans);
    return ans ;
}

// OR - Change in base case condition

void possiblePaths(Node* root, vector<int>& temp, vector<vector<int>>& ans){
    if(root == NULL)    return  ;
    
    temp.push_back(root->data) ;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp) ;
    }
    possiblePaths(root->left, temp, ans);
    possiblePaths(root->right, temp, ans);
    
    temp.pop_back() ;   //going back, so pop out the element
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> ans ;
    if(root == NULL)    return ans ;
    
    vector<int> temp ;
    possiblePaths(root, temp, ans);
    return ans ;
}
