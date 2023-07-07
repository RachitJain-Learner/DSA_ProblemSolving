// G-22. Kahn's Algorithm | Topological Sort Algorithm | BFS

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    // making AdjList
    vector<int> adj[V] ;
    for(int i=0 ; i< e ; ++i){
        adj[edges[i][0]].push_back(edges[i][1]) ;
    }
    // Making indegree array from adjList
    int indegree[V] = {0};
    for(int i=0 ; i<V ; i++){
        for(auto node: adj[i]){
            indegree[node]++ ;
        }
    }
    // Using BFS - make queue
    queue<int> q ;
    // initialising queue with 0 indegree
    for(int i=0 ; i<V ; ++i){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans ;
    while(!q.empty()){
        int node = q.front() ;
        q.pop() ;
        
        ans.push_back(node) ;
        for(auto temp: adj[node]){
            indegree[temp]-- ;
            if(indegree[temp] == 0)
                q.push(temp) ;
        }
    }
    return ans ;
}