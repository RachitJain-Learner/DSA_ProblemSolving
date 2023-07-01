// L25. Check for Symmetrical Binary Trees 

bool sameSubTree(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    
    if(root1 == NULL || root2 == NULL){
        return root1 == root2 ;
    }
    bool oueterTree =  sameSubTree(root1->left, root2->right) ;
    bool innerTree =  sameSubTree(root1->right, root2->left) ;

    return (root1->data == root2->data) && innerTree && outerTree ;
}

// Base case - different way
bool sameSubTree(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL && root2 == NULL){
        return true ;
    }
    else if(root1 == NULL || root2 == NULL)    return false ;

    bool leftTree =  sameSubTree(root1->left, root2->right) ;
    bool rightTree =  sameSubTree(root1->right, root2->left) ;

    return root1->data == root2->data && leftTree && rightTree ;
}

bool isSymmetric(BinaryTreeNode<int>* root)
{   
    if(root == NULL)    
        return true ;
    
    return sameSubTree(root->left, root->right) ; 
}