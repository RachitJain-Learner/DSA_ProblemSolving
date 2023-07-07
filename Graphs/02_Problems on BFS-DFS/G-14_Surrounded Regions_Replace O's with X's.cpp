// G-14. Surrounded Regions | Replace O's with X's 

// Start with boundary cells
class Solution{
private: 
    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<char>>& vis, int n, int m, int drow[], int dcol[]){
        vis[row][col] = 'O' ;
        
        for(int i=0 ; i< 4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m
                && mat[nrow][ncol] == 'O' && vis[nrow][ncol] == 'X' ){
                dfs(nrow, ncol, mat, vis, n, m, drow, dcol);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> vis(n, vector<char>(m, 'X')) ;
        
        int drow[] = {-1, 0, 1, 0} ;
        int dcol[] = {0, 1, 0, -1} ;
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(mat[i][j] == 'O'){
                        dfs(i, j, mat, vis, n, m, drow, dcol);
                    }
                }
            }
        }
        return vis ;
    }
};