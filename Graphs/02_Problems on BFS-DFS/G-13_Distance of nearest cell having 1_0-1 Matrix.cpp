// G-13. Distance of nearest cell having 1 | 0/1 Matrix

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{   
	    int n = grid.size() ;
	    int m = grid[0].size() ;
	    
	    // use vis vector to get filled 2D matrix with 0 and 
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    
	    queue<pair<pair<int, int>, int>> q ;
	   // Push all 1 elements of grid inside queue
	    for(int i=0; i<n ; i++){
	        for(int j=0 ; j<m ; j++){
	            if(grid[i][j] == 1){
	                q.push({{i, j}, 0}) ;
	                vis[i][j] = 1 ;
	               // dist[i][j] = 0 ;
	            }
	           // else{
	           //     vis[i][j] = 0 ;
	           // }
	        }
	    }
	    while(!q.empty()){
	        int row = q.front().first.first ;
	        int col = q.front().first.second ;
	        int steps = q.front().second ;
	        q.pop() ;
	        
	        dist[row][col] = steps ;    //or do this when pushing into queue
	        
	        int delrow[] = {-1, 0, 1, 0} ;
	        int delcol[] = {0, 1, 0, -1} ;
	        for(int i=0 ; i<4 ; i++){
	            int nrow = row + delrow[i] ;
	            int ncol = col + delcol[i] ;
	            
	            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && 
	                vis[nrow][ncol] == 0){
	                    vis[nrow][ncol] = 1 ;
	                    q.push({{nrow, ncol}, steps+1}) ;
	                   // dist[nrow][ncol] = steps+1 ;
	            }
	        }
	    }
	    return dist ;
	}
};