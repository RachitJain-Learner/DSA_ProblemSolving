// 23. Bottom View of Binary Tree 

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans ;
    if(root == NULL)
		return ans ;
	
	map<int, int> nodes ;     // hd, front->data   //creation 
	queue<pair<BinaryTreeNode<int>*, int>> topNode ;
	
	topNode.push({root, 0}) ;        //push root 
	
	while(!topNode.empty()){        // work until it is empty
		auto temp = topNode.front() ;   // accessing frontNode
		topNode.pop() ;
		
		auto front = temp.first ;    //assigning 
		int hd = temp.second ;
		
		nodes[hd] = front->data ;  		//mapping
		
		if(front->left)             //pushing left & right nodes into map
			topNode.push({front->left , hd-1}) ;
		if(front->right)
			topNode.push({front->right, hd+1}) ;
	}
	for(auto i : nodes){               // pushing map content into ans
			ans.push_back(i.second) ;
	}
	return ans ;
}


