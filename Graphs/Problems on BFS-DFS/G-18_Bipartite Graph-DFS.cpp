// G-18_Bipartite Graph-DFS

bool checkByDFS(int node, int iniColor, vector<int>& color, vector<int> adj[]){
	color[node] = iniColor ;

	for(int temp: adj[node]){
		if(color[temp] == -1){
			if(checkByDFS(temp, !iniColor, color, adj) == false)
				return false;
		}
		else if(color[temp] == iniColor){
			return false ;
		}
	}
	return true ;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size() ;
	int m = edges[0].size() ;
	
	// making adjList from adjMatrix
	vector<int> adj[n] ;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(edges[i][j] == 1){
				adj[i].push_back(j) ;
			}
		}
	}
	// DFS
	vector<int> color(n, -1);
	for(int i=0; i<n ; i++){
		if(color[i] == -1){
			if(checkByDFS(i, 1, color, adj) == false)
				return false;
		}
	}
	return true ;
}