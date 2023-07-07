// G-10_Rotten Oranges - Using BFS to calculate min time - BFS multisource

// Method - 1 - with for loop at last 
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        // Using BFS to calculate min time
        queue<pair<pair<int, int>, int>> q ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0}) ;
                    vis[i][j] = 2 ;
                }
            }
        }
        int totalTime = 0;
        int delrow[] = {-1, 0, 1, 0} ;
        int delcol[] = {0, 1, 0, -1} ;

        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int time = q.front().second ;
            q.pop() ;
            
            totalTime = max(time, totalTime) ;
            
            for(int i=0 ; i<4 ; i++){
                int nrow = row + delrow[i] ;
                int ncol = col + delcol[i] ;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0 ){
                    q.push({{nrow, ncol}, time+1}) ;
                    vis[nrow][ncol] = 2 ;
                }
            }
        }
        for(int i=0 ; i<n  ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1)
                    return -1 ;
            }
        }
        return totalTime ;
    }
};

// Method - 2
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        // vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        int vis[n][m] ;
        int cntFresh = 0 ;
        
        // Using BFS to calculate min time
        queue<pair<pair<int, int>, int>> q ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0}) ;
                    vis[i][j] = 2 ;
                }
                else{
                    vis[i][j] = 0 ;
                }
                if(grid[i][j] == 1)  cntFresh++ ;
            }
        }
        int cnt = 0 ;
        int totalTime = 0;
        int delrow[] = {-1, 0, 1, 0} ;
        int delcol[] = {0, 1, 0, -1} ;
        
        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int time = q.front().second ;
            q.pop() ;
            
            totalTime = max(time, totalTime) ;
            
            for(int i=0 ; i<4 ; i++){
                int nrow = row + delrow[i] ;
                int ncol = col + delcol[i] ;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&   vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1 ){
                    q.push({{nrow, ncol}, time+1}) ;
                    vis[nrow][ncol] = 2 ;
                    cnt++ ;
                }
            }
        }
        if(cntFresh != cnt) return -1 ;

        return totalTime ;
    }
};