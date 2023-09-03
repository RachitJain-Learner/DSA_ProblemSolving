// 10. Iterative Inorder Traversal in Binary Tree 

// Method-1 : InterviewBit Solution
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans ;
    if(A == NULL){
        return ans ;
    }
    stack<TreeNode*> st ;
    TreeNode* node = A ;
    
    while(!st.empty() || node){
        if(node){
            st.push(node) ;
            node = node->left ;
        }
        else{
            node = st.top() ;
            st.pop() ;
            
            ans.push_back(node->val) ;
               
            node = node->right ;   
        }        
    }
    return ans ;
}


// Method-2 : Striver Solution
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
