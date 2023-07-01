// 10. Iterative Inorder Traversal in Binary Tree 

vector<int> getInOrderTraversal(TreeNode *root)
{	
	vector<int> ans ;
    if(root == NULL)    
        return ans ;

    stack<TreeNode*> st ;
    // TreeNode* temp = root; OR
    st.push(root) ;
    TreeNode* temp = root->left ;

    while(true){
        if(temp != NULL){
            st.push(temp) ;
            temp = temp->left ;
        }
        else{
            if(st.empty() == true)
                break ;

            temp = st.top() ;
            st.pop() ;
            ans.push_back(temp->data) ;

            temp = temp->right ;
        }
    }
	return ans ;
}
