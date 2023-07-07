// G-8. Number of Islands | Number of Connected Components in Matrix 

class Solution {
  private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int drow[], int dcol[], int n, int m){
        vis[row][col] = 1 ;
        for(int i=0 ; i< 8 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
            grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                dfs(nrow, ncol, grid, vis, drow, dcol, n, m) ;    
            }
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0} ;
        int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1} ;
        
        int cntIsland = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    dfs(i, j, grid, vis, drow, dcol, n, m) ;
                    cntIsland++ ;
                }
            }
        }
        return cntIsland ;
    }
};