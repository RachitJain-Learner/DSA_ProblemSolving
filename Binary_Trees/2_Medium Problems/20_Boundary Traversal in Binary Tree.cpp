// 20. Boundary Traversal in Binary Tree

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };
************************************************************/

bool isLeaf(TreeNode<int>* root){
	// if(root == NULL) return false ;
	return root->left == NULL && root->right == NULL ;	
}
void addLeftBoundary(TreeNode<int>* root, vector<int>& ans){
	TreeNode<int>* node = root->left ;
	
	while(node && !isLeaf(node)){
		ans.push_back(node->data);
		if(node->left)
			node = node->left ;
		else
			node = node->right ;
	}
}
void addLeaves(TreeNode<int>* root, vector<int>& ans){
	// if(root == NULL)	return ;	//no need otherwise dont use if cond and return
	
	if(isLeaf(root)){
		ans.push_back(root->data);
		return ;
	}	
	if(root->left)  addLeaves(root->left, ans);
	if(root->right)  addLeaves(root->right, ans);
}
void addRightBoundary(TreeNode<int>* root, vector<int>& ans){
	// if(root == NULL)	return ;	no need
	TreeNode<int>* node = root->right ;
	
	vector<int> temp ;
	while(node && !isLeaf(node)){
		temp.push_back(node->data);
		if(node->right)
			node = node->right ;
		else
			node = node->left ;	
	}
	for(int i=temp.size()-1 ; i >= 0 ; i--){
		ans.push_back(temp[i]);
	}
}
vector<int> traverseBoundary(TreeNode<int>* root){
	vector<int> ans ;
    if(root == NULL)
		return ans ;

	if(!isLeaf(root)){
		ans.push_back(root->data);
	}
	
	addLeftBoundary(root, ans);
	addLeaves(root, ans);
	addRightBoundary(root, ans);

	return ans;
}