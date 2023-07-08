// G-20_Find Eventual Safe States-DFS.cpp

#include <bits/stdc++.h> 

bool detectCycleDfs(int node, int vis[], int visPath[], vector<int> adjLis[]){
    vis[node] = 1 ;
    visPath[node] = 1 ;

    for(auto temp: adjLis[node]){
        if(!vis[temp]){
            if(detectCycleDfs(temp, vis, visPath, adjLis))
                return true ;
        }
        else if(visPath[temp] == 1){
            return true ;
        }
    }
    visPath[node] = 0;
    return false ;
}

vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    vector<int> adjLis[n] ;
    for(auto it: edges){
        adjLis[it[0]].push_back(it[1]) ;
    }
    int vis[n] = {0} ;
    int visPath[n] = {0} ;
    
    for(int i=0 ; i< n ; i++){
        if(!vis[i]){
            detectCycleDfs(i, vis, visPath, adjLis);
        }
    }
    //  visPath is marked 0, when nodes don't contribute to cycle else marked 1
    vector<int> ans ;
    for(int i=0 ; i< n ;i++){
        if(visPath[i] == 0){
            ans.push_back(i);
        }
    }
    return ans ;
}