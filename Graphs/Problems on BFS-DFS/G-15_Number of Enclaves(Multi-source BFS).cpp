// G-15. Number of Enclaves | Multi-source BFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        queue<pair<int, int>> q ;
        // Figure out boundary 1s and put into queue ds
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                // first row, first col, last row, last col
                if(i == 0 || i == n-1 || j == 0 || j == m-1 ){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1 ;
                    }
                }
            }
        }
        int drow[] = {-1, 0, 1, 0} ;
        int dcol[] = {0, 1, 0, -1} ; 

        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            // traverse in all 4 direction
            for(int i=0 ; i<4 ; i++){
                int nrow = row + drow[i] ;
                int ncol = col + dcol[i] ;
                // consider movement cond + not visited + land cell
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1 ;
                    q.push({nrow, ncol}) ;
                }
            }
        }
        int cnt = 0 ;
        //  this loop can be replaced by cntOne at initial stage like rotten oranges prob. 
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] != grid[i][j])
                    cnt++ ;
            }
        }
        return cnt ;
    }
};