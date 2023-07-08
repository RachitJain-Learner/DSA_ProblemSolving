// G-25. Find Eventual Safe States - BFS - Topological Sort

//Approach - Reverse edges of graph & apply TopoSort BFS
class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        //  Reverse the edges of graph & make indegree array
        vector<int> revAdj[V] ;
        int indegree[V] = {0} ;
        for(int i=0 ; i< V ; i++){
            for(auto node: adj[i]){
                revAdj[node].push_back(i) ;
                indegree[i]++ ;     //calc. indegree of revAdj List
            }
        }
        //  Initialising the queue
        queue<int> q ;
        for(int i=0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        vector<int> ans ;
        //  Traversing the queue
        while(!q.empty()){
            int temp = q.front() ;
            q.pop() ;
            
            ans.push_back(temp) ;
            for(auto neighbour: revAdj[temp]){
                indegree[neighbour]-- ;
                if(indegree[neighbour] == 0){
                    q.push(neighbour) ;
                }
            }
        }
        sort(ans.begin(), ans.end()) ;
        return ans ;
    }
};