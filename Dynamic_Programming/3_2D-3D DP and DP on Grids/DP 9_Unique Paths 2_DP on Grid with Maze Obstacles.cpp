int mod = 1e9+7 ;

// Space Optimisation
int solveSpaceOptim(vector<vector<int>> &mat, int n, int m){
    vector<int> prev(m, 0) ;
    vector<int> curr(m, 0) ;

    for(int row=n-1 ; row >= 0 ; row--){
        for(int col=m-1 ; col >= 0 ; col--){
            if(row == n-1 && col == m-1){
                curr[col] = 1 ;
            }
            else if(mat[row][col] == -1)
                curr[col] = 0 ;
            else{
                int right = 0 ;
                if(col+1 < m) right = curr[col+1] % mod ;
                
                int down = 0 ;
                if(row+1 < n) down = prev[col] % mod ;

                curr[col] = right + down ;
            }
        }
        prev = curr ;
    }
    return prev[0] ;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return solveSpaceOptim(mat, n, m) % mod ;
}

// Tabulation
int solveTab(vector<vector<int>> &mat, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, 0)) ;

    // Best way to consider each and every case
    // take all if cond. inside for loop
    for(int row=n-1 ; row >= 0 ; row--){
        for(int col=m-1 ; col >= 0 ; col--){
            if(row == n-1 && col == m-1){
                dp[row][col] = 1 ;
            }
            else if(mat[row][col] == -1)
                dp[row][col] = 0 ;
            else{
                int right = 0 ;
                if(col+1 < m) right = dp[row][col+1] % mod ;
                
                int down = 0 ;
                if(row+1 < n) down = dp[row+1][col] % mod ;

                dp[row][col] = right + down ;
            }
        }
    }
    return dp[0][0] ;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return solveTab(mat, n, m) % mod ;
}

// Recursion + Memoization
int solve(int row, int col, vector<vector<int>> &mat, int n, int m, vector<vector<int>>& dp){
    
    if(row == n-1 && col == m-1){
        return 1 ;
    }
    // Out of bound cond. should be checked before accessing the index
    if(row >= n || col >= m){
        return 0 ;
    }
    if(mat[row][col] == -1)
        return 0 ;

    if(dp[row][col] != -1){
        return dp[row][col] ;
    }
    int right = solve(row, col+1, mat, n, m, dp) % mod ;
    int down = solve(row+1, col, mat, n, m, dp) % mod ;

    return dp[row][col] = right + down ;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    return solve(0, 0, mat, n, m, dp) % mod ;
}