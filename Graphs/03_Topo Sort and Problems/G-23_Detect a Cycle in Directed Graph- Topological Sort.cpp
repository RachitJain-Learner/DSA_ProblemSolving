// G-23. Detect a Cycle in Directed Graph | Topological Sort | Kahn's Algorithm | BFS

#include<bits/stdc++.h>

// using TopoSort BFS
int detectCycleInDirectedGraph(int n, vector<pair<int,int>>& edges) {
  // make adjacency List
  vector<int> adjLis[n+1] ;
  for(auto it: edges){
    adjLis[it.first].push_back(it.second) ;
  }
  
  // build indegree array
  int indegree[n+1]={0};
  for(int i=1 ; i<=n ; i++){
    for(auto node: adjLis[i] )
      indegree[node]++ ;
  }

  // initialising queue
  queue<int> q ;
  for(int i=1 ; i<=n ; ++i){
    if(indegree[i] == 0){
      q.push(i) ;
    }
  }
  int cntnodes = 0 ;
  while(!q.empty()){
    int node = q.front() ;
    q.pop() ;
    
    cntnodes++ ;  //for getting elements in TopoSort order
    for(auto adjacent: adjLis[node]){
      indegree[adjacent]-- ;
      if(indegree[adjacent] == 0){
        q.push(adjacent) ;
      }
    }
  }
  // if count of TopoSort order is same as nodes, then no cycle is present
  if(cntnodes == n){
    return false ;
  }
  return true ;
}