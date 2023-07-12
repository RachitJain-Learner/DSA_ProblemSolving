// L37. Morris Traversal | Preorder

// Case-1 : if node->left is not present, print node and move to right
// Case-2 : if node->left is present, take it(make a variable for traversing)
// Move to rightmost node, if found NULL ie. thread is not present, make thread, print node and move node to left

// if cond. helps to move to node with the help of thread and
// then again traverse same path to remove the thread, and move to right

void preOrder(BinaryTreeNode<int> *root) {
	
	BinaryTreeNode<int>* node = root ;
	while(node){
		if(node->left == NULL){
			cout<< node->data<<" " ;
			node = node->right ;
		}
		else{
			BinaryTreeNode<int>* temp = node->left ;
			while(temp->right && temp->right != node){
				temp = temp->right ;
			}
			if(temp->right == NULL){
				temp->right = node ;	//make a thread
				cout<< node->data <<" " ;
				node = node->left ;
			}
			else{
				temp->right = NULL ;	//remove thread
				node = node->right ;
			}
		}
	}
}