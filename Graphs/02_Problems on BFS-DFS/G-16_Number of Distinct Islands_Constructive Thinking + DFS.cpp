// G-16. Number of Distinct Islands | Constructive Thinking + DFS

// Approach: use set data structure to store configuration of island & subtraction from 
// base_row, base_col and rest code remains same of traversing(No. of islands)
class Solution {
private: 
    void solveDfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
    int delrow[], int delcol[], vector<pair<int, int>>& temp, int row0, int col0 ){
        vis[row][col] = 1 ;
        temp.push_back({row-row0, col-col0}) ;
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        for(int i=0 ; i<4 ; i++){
            int nrow = row + delrow[i] ;
            int ncol = col + delcol[i] ;
            if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    solveDfs(nrow, ncol, vis, grid, delrow, delcol, temp, row0, col0) ;
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        // unordered_set<vector<pair<int, int>>> st ;   ?? not working
        set<vector<pair<int, int>>> st ;
        
        int delrow[] = {-1, 0, 1, 0} ;
        int delcol[] = {0, 1, 0, -1} ;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> temp ;
                    solveDfs(i, j, vis, grid, delrow, delcol, temp, i, j) ;
                    st.insert(temp) ;
                }
            }
        }
        return st.size() ;
    }
};