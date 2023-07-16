// Inorder Morris Traversal

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> ans ;

    TreeNode *node = root ;
    while(node) {
        if(node->left == NULL){
            ans.push_back(node->data) ;
            node = node->right ;
        }
        else{
            TreeNode *temp = node->left ;
            while(temp->right && temp->right != node){
                temp = temp->right ;
            }
            if(temp->right == NULL){
                temp->right = node ;
                node = node->left ;
            }
            else{
                temp->right = NULL ;
                ans.push_back(node->data) ;
                node = node->right ;
            }
        }
    }
    return ans ;
}
