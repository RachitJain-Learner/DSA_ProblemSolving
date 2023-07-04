// 11. Iterative Postorder Traversal using 2 Stack 

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans ;
    if(root == NULL)    return ans ;

    stack<TreeNode*> st1, st2 ;
    st1.push(root) ;

    while(!st1.empty()){
        auto node = st1.top() ;
        st1.pop() ;

        if(node->left)  
            st1.push(node->left);

        if(node->right)  
            st1.push(node->right);

        st2.push(node);
    }
    while(!st2.empty()){
        int temp = st2.top()->data ;
        ans.push_back(temp);
        st2.pop() ;
    }   
    return ans ;
}