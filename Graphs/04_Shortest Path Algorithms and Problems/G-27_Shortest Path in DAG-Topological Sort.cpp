// G-27. Shortest Path in Directed Acyclic Graph - Topological Sort

void solveDfs(int node, stack<int>& st, int vis[], vector<pair<int,int>> adjLis[]){
    vis[node] = 1 ;

    for(auto neighbour: adjLis[node]){
        if(!vis[neighbour.first]){
            solveDfs(neighbour.first, st, vis, adjLis) ;
        }
    }
    st.push(node) ;
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // making adjacency list
    vector<pair<int, int>> adjLis[n] ;
    for(auto it: edges){
        adjLis[it[0]].push_back({it[1], it[2]});
    }
    // solve by DFS TopoSort
    stack<int> st ;
    int vis[n] = {0} ;
    for(int i=0 ; i< n ; i++){
        if(!vis[i]){
            solveDfs(i, st, vis, adjLis) ;
        }
    }
    // Pop from queue & update distance array
    vector<int> dist(n, 1e9) ;
    dist[0] = 0 ;
    while(!st.empty()){
        int node = st.top() ;
        st.pop() ;

        for(auto neighbour: adjLis[node]){
            if(dist[neighbour.first] > dist[node]+neighbour.second ){
                dist[neighbour.first] = dist[node]+neighbour.second ;
            }
        }
    }
    // replace non-reachable index with -1
    for(auto &it: dist){
        if(it == 1e9){
            it = -1 ;
        }
    }
    return dist ;
}
