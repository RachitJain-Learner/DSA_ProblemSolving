// DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points 

#include <bits/stdc++.h> 

// Good - To Do Question
// Space Optimisation
int solveSpaceOptim(vector<vector<int>> &matrix){
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    
    vector<int> prev(m, 0) ;
    vector<int> curr(m, 0) ;

    for(int col = 0; col < m ; col++){
        prev[col] = matrix[n-1][col] ;
    }
    for(int row = n-2 ; row >= 0 ; row--){
        for(int col= m-1 ; col >= 0 ; col--){
            int down = prev[col] ;
            
            int leftDiag = INT_MIN ;
            if(col-1 >= 0) leftDiag = prev[col-1] ;
            
            int rightDiag = INT_MIN ;
            if(col+1 <= m-1) rightDiag = prev[col+1] ;

            curr[col] = matrix[row][col] + max(down, max(leftDiag, rightDiag)) ;
        }
        prev = curr ;
    }
    // we need to find max from start point as first row
    int maxSum = INT_MIN ;
    for(int col=0 ; col<m ; col++){
        maxSum = max(maxSum, prev[col]) ;
    }
    return maxSum ;
}
int getMaxPathSum(vector<vector<int>> &matrix){
    return solveSpaceOptim(matrix) ;
}


//  Tabulation 
int solveTab(vector<vector<int>> &matrix, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, 0)) ;

    for(int col = 0; col < m ; col++){
        dp[n-1][col] = matrix[n-1][col] ;
    }
    for(int row = n-2 ; row >= 0 ; row--){
        for(int col= m-1 ; col >= 0 ; col--){
            int down = dp[row+1][col] ;
            
            int leftDiag = INT_MIN ;
            if(col-1 >= 0) leftDiag = dp[row+1][col-1] ;
            
            int rightDiag = INT_MIN ;
            if(col+1 <= m-1) rightDiag = dp[row+1][col+1] ;

            dp[row][col] = matrix[row][col] + max(down, max(leftDiag, rightDiag)) ;
        }
    }
    int maxSum = INT_MIN ;
    for(int col=0 ; col<m ; col++){
        maxSum = max(maxSum, dp[0][col]) ;
    }
    return maxSum ;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    return solveTab(matrix) ;
}


// Recursion + Memoization
int solveMemo(int row, int col, vector<vector<int>> &matrix, int n, int m, vector<vector<int>>& dp){
    
    // Inside bounds, then check inside
    if(col >= m || col < 0)
        return INT_MIN ;

    if(row == n-1){
        return matrix[row][col] ;
    }
    if(dp[row][col] != -1){
        return dp[row][col] ;
    }
    int down = solveMemo(row+1, col, matrix, n, m, dp) ;
    int leftDiag = solveMemo(row+1, col-1, matrix, n, m, dp) ;
    int rightDiag = solveMemo(row+1, col+1, matrix, n, m, dp) ;

    return dp[row][col] = matrix[row][col] + max(down, max(leftDiag, rightDiag)) ;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size() ;
    int m = matrix[0].size() ;
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;

    int maxSum = INT_MIN ;
    for(int col=0 ; col<m ; col++){
        maxSum = max(maxSum, solveMemo(0, col, matrix, n, m, dp)) ;
    }
    return maxSum ;
}


// Recursion
int solve(int row, int col, vector<vector<int>> &matrix, int n, int m){
    // if(row >= n || col >= m || col < 0) not needed since moving in 
    // only col and dest. is last row and not single block, therefore no row boundations
    // Inside bounds, then check
    if(col >= m || col < 0)
        return INT_MIN ;

    // if(row == n-1 && col <= m-1 && col >= 0){
    if(row == n-1){
        return matrix[row][col] ;
    }
    
    int down = solve(row+1, col, matrix, n, m) ;
    int leftDiag = solve(row+1, col-1, matrix, n, m) ;
    int rightDiag = solve(row+1, col+1, matrix, n, m) ;

    return matrix[row][col] + max(down, max(leftDiag, rightDiag)) ;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size() ;
    int m = matrix[0].size() ;

    int maxSum = INT_MIN ;
    for(int col=0 ; col < m ; col++){
        maxSum = max(maxSum, solve(0, col, matrix, n, m)) ;
    }
    return maxSum ;
}