// DP 10. Minimum Path Sum in Grid |

#include <bits/stdc++.h> 

// Recursion + Memoization
int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>>& dp, int n, int m){
    if(row == n-1 && col == m-1){
        return grid[row][col] ;
    }
    if(row >= n || col >= m){
        return INT_MAX ;
    }
    if(dp[row][col] != -1){
        return dp[row][col] ;
    }
    int right = solve(row+1, col, grid, dp, n, m) ;
    int down = solve(row, col+1, grid, dp, n, m) ;

    return dp[row][col] = grid[row][col] + min(right, down) ;
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;

    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    return solve(0, 0, grid, dp, n, m) ;
}