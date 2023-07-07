// G-24. Course Schedule II | Pre-requisite Tasks | Topological Sort

// By DFS Topo Sort Ordering using stack --> NOT Possible
// By BFS Topo Sort Ordering using indegree array --> for confirming about DAG structure
class Solution
{ 
  private:
    void solveBfs(queue<int>& q , int indegree[], vector<int>& ans, vector<int> adjLis[]){
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;
            
            for(auto temp: adjLis[node]){
                indegree[temp]-- ;
                if(indegree[temp] == 0)
                    q.push(temp) ;
            }
        }
    }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        // making adjList
        vector<int> adjLis[n];
        for(int i=0 ; i<m ; i++){
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;
            
            adjLis[v].push_back(u) ;
        }
        // making indegree array
        int indegree[n] = {0} ;
        for(int i=0 ; i<n ; i++){
            for(auto node: adjLis[i]){
                indegree[node]++ ;
            }
        }
        // Initialising queue for BFS Topological Sort
        queue<int> q ;
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0)
                q.push(i) ;
        }
        vector<int> ans ;
        solveBfs(q, indegree, ans, adjLis);
        
        return (ans.size() == n) ? ans : vector<int>() ;
    }
};