// G-19. Detect cycle in a directed graph using DFS 
// cycle in same path is considered as cycle, making use of visPath[]
class Solution {
  private: 
    bool checkCycle(int node, int vis[], int visPath[], vector<int> adj[]){
        vis[node] = 1 ;
        visPath[node] = 1 ;
        
        for(auto temp: adj[node]){
            if(!vis[temp]){
                if(checkCycle(temp, vis, visPath, adj) == true)
                    return true ;
            }
            else if(visPath[temp] == 1){
                return true ;
            }
        }
        visPath[node] = 0 ; // when moving back, unmark the visited path
        return false ;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0} ;
        int visPath[V] = {0} ;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(checkCycle(i, vis, visPath, adj) == true)
                    return true ;
            }
        }
        return false ;
    }
};