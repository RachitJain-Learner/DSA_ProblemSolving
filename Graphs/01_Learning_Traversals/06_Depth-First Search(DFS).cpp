// G-06_Depth-First Search(DFS).cpp

#include <bits/stdc++.h>
using namespace std;

// Function to return a list containing the DFS traversal of the graph.
class Solution {
  private:
    void dfs(int start, int V, vector<int> adj[], int *vis, vector<int>& ans){
        vis[start] = 1;
        ans.push_back(start);
        
        for(auto node: adj[start]){
            if(!vis[node]){
                dfs(node, V, adj, vis, ans);
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        int vis[V] = {0} ;
        dfs(0, V, adj, vis, ans);
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}