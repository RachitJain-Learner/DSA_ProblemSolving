// L22. Top View of Binary Tree

// Approach - only extra - keeping track of hd distance in queue & using map data structure 
#include <bits/stdc++.h> 
/************************************************************
    Following is the TreeNode class structure:
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans ;
    if(root == NULL)
        return ans ;

    // BFS
    map<int, int> mp ;
    queue<pair<TreeNode<int>*, int>> q ;
    q.push({root, 0}) ;
    
    while(!q.empty()){
        auto node = q.front().first ;
        int hd = q.front().second ;
        q.pop() ;

        if(mp.find(hd) == mp.end()){
            mp[hd] = node->val ;
        }

        if(node->left)
            q.push({node->left, hd-1});
        if(node->right)
            q.push({node->right, hd+1});
    }
    for(auto it: mp){
        ans.push_back(it.second) ;
    }
    return ans ;
}