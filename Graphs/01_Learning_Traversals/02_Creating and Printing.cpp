// Creating and Printing

#include <bits/stdc++.h> 
vector <vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> ans ;

    //creating Adjacency List 
    vector<int> adjList[n] ;
    for(auto it: edges){
        adjList[it[0]].push_back(it[1]) ;
        adjList[it[1]].push_back(it[0]) ;
    }

    // Printing Adjacency List
    for(int i=0 ; i<n ; i++){
        vector<int> temp ;
        temp.push_back(i) ;
        for(auto it: adjList[i]){
            temp.push_back(it) ;
        }
        ans.push_back(temp) ;
    }
    return ans ;
}