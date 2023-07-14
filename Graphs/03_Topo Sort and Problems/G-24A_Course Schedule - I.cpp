// G-23_Course Schedule - I.cpp - Topological Sort

#include <bits/stdc++.h> 

// Using TopoSort BFS - cyclic detection of DAG
string canFinish(vector<vector<int>>& prerequisites, int n, int m)
{   
    // when no edges, base case not necessary but save time
    if(m == 0)  return "Yes" ;
    
    // making AdjList
    vector<int> adjLis[n+1];
    for(int i=0 ; i< m ; i++){
        int u = prerequisites[i][0] ;
        int v = prerequisites[i][1] ;
        adjLis[v].push_back(u) ;
    }
    // making indegree array
    int indegree[n+1] = {0} ; 
    for(int i=1 ; i<=n ; i++){
        for(auto node: adjLis[i]){
            indegree[node]++ ;
        }
    }
    // initial queue
    queue<int> q ;
    for(int i=1 ; i<= n ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    // queue Traversal
    int cnt = 0 ;
    while(!q.empty()){
        int temp = q.front() ;
        q.pop() ;

        cnt++ ;
        for(auto node: adjLis[temp]){
            indegree[node]--;
            if(indegree[node] == 0){
                q.push(node) ;
            }
        }
    }
    return (cnt == n) ? "Yes" : "No" ; 
}


// Leetcode - trying another way
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // making adjacencyList & indegree array
        vector<int> adjList[numCourses] ;
        vector<int> indegree(numCourses, 0) ;
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]) ;
            indegree[it[0]]++ ;
        }
        
        // Initialising the queue
        queue<int> q ;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i] == 0)
                q.push(i) ;
        }

        // Traversing queue nodes
        int countNodes = 0 ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;

            countNodes++ ;

            for(auto temp: adjList[node]){
                indegree[temp]-- ;
                if(indegree[temp] == 0){
                    q.push(temp) ;
                }
            }
        }
        return countNodes == numCourses ;
    }
};
