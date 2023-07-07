// G-21. Topological Sort Algorithm | DFS

class Solution
{   
private:
    void dfsTopoSort(int node, int vis[], stack<int>& st, vector<int> adj[]){
        vis[node] = 1 ;
        for(int adjNode: adj[node]){
            if(!vis[adjNode]){
                dfsTopoSort(adjNode, vis, st, adj) ;
            }
        }
        // when no further calls are left, ie. DFS is completed for a node,
        //  then push into stack
        st.push(node) ;
    }
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0} ;
	    stack<int> st ;
	    
	    for(int i=0 ; i<V ; i++){
	        if(vis[i] == 0){
	            dfsTopoSort(i, vis, st, adj);
	        }
	    }
	    vector<int> ans ;
	    while(!st.empty()){
	        ans.push_back(st.top()) ;
	        st.pop() ;
	    }
	    return ans ;
	}
};