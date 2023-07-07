// Problems on BFS-DFS/G-12_Detect a Cycle in an Undirected Graph using DFS.cpp

class Solution{
  public:
    bool detectCycle(int src, int parent, int vis[], vector<int> adj[]){
        vis[src] = 1 ;
        for(auto node: adj[src]){
            if(!vis[node]){
                if(detectCycle(node, src, vis, adj))    
                    return true ;
            }
            else if(parent != node){
                return true ;
            }
        }
        return false ;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(detectCycle(i, -1, vis, adj))    
                    return true ;
            }
        }
        return false ;
    }
};