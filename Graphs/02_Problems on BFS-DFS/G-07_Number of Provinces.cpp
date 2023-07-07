// Problems on BFS-DFS/G-07_Number of Provinces.cpp

class Solution {
  private: 
    void dfs(int start, vector<int> adjLs[], int vis[]){
        vis[start] = 1 ;
        for(auto node: adjLs[start]){
            if(!vis[node]){
                dfs(node, adjLs, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        // converting Adj Matrix into Adj List
        vector<int> adjLs[V];
        for(int i=0; i<V ; i++){
            for(int j=0 ; j<V ; j++){
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    // adjLs[j].push_back(i); no need
                }
            }
        }
        // DFS Traversal
        int vis[V] = {0};
        int count = 0 ;
        
        for(int i=0; i<V; i++){   // for connected components
            if(!vis[i]){
                count++ ;
                dfs(i, adjLs, vis);
            }
        }
        return count ;
    }
};