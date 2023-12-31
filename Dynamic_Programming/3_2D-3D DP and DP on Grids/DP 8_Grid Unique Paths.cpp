// DP 8. Grid Unique Paths
#include <bits/stdc++.h> 

// Space Optimisation
// Method - 1 
int solve(int row, int col){
	vector<int> prev(col, 1) ;
	vector<int> curr(col, 1) ;
	
	for(int m=1 ; m<row ; m++){
		for(int n=1 ; n<col ; n++){
			curr[n] = curr[n-1] + prev[n] ;
		}
		prev = curr ;
	}
	return prev[col-1] ;
}

// Method-2 - explicitly/manually filling the prev & curr 
int solve(int row, int col){
	vector<int> prev(col, 0) ;
	vector<int> curr(col, 0) ;
	
	prev[0] = 1 ;
	for(int i=1 ; i<col ; i++)
		prev[i] = prev[i-1] ;
	
	curr[0] = prev[0] ;

	for(int m=1 ; m<row ; m++){
		for(int n=1 ; n<col ; n++){
			curr[n] = curr[n-1] + prev[n] ;
		}
		prev = curr ;
	}
	return prev[col-1] ;
}
int uniquePaths(int m, int n) {
	return solve(m, n) ;
}

// Method-3
int uniquePaths(int m, int n) {
        vector<int> prev(n, 0) ;
        vector<int> curr(n, 0) ;
        
        // learning--> m-1 in for-loop(m-1 to 0) is curr
        curr[n-1] = 1 ;
        for(int row=m-1 ; row >= 0 ; row--){
            for(int col=n-2 ; col >= 0 ; col--){
                if(row == m-1 && col == n-1) continue ;  //curr[n-1] = 1 
                
                int down = 0, right = 0 ;
                if(row < m-1) down = prev[col] ;	//row+1 = m -> prev, row = m-1 -> curr
                if(col < n-1) right = curr[col+1] ;

                curr[col] = down + right ;
            }
            prev = curr ;
        }
        return prev[0] ;
    }

//  Tabulation 
int uniquePaths(int m, int n) {
    // filling the first row & first col with 1 works since there is no 
	// obstruction in path when you reach last row & last col
	// but not a good way
	vector<vector<int>> dp(m+1, vector<int>(n+1, 1)) ;
	int row = m ;
	int col = n ;

	for(int m=2 ; m<= row ; m++){
		for(int n=2 ; n <=col ; n++){
			dp[m][n] = dp[m][n-1] + dp[m-1][n] ;
		}
	}
	return dp[m][n] ;
}
// OR
int solve(int row, int col){
	vector<vector<int>> dp(row, vector<int>(col, 0)) ;
	
    // externally filling last row and col
	dp[0][0] = 1 ;
	for(int i=1 ; i<col ; i++)
		dp[0][i] = dp[0][i-1] ;

	for(int i=1 ; i<row ; i++)
		dp[i][0] = dp[i-1][0] ;

	for(int m=1 ; m<row ; m++){
		for(int n=1 ; n<col ; n++){
			dp[m][n] = dp[m][n-1] + dp[m-1][n] ;
		}
	}
	return dp[row-1][col-1] ;
}
int uniquePaths(int m, int n) {
	return solve(m, n) ;
}

// Method-3 : Striver Approach
// considered base case inside for-loop -->  imp to use continue if case
int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0)) ;
        
        dp[m-1][n-1] = 1 ;
        for(int row=m-1 ; row >= 0 ; row--){
            for(int col=n-1 ; col >= 0 ; col--){
                if(row == m-1 && col == n-1) continue ;  //dp[m-1][n-1] = 1 
                
                int down = 0, right = 0 ;
                if(row < m-1) down = dp[row+1][col] ;
                if(col < n-1) right = dp[row][col+1] ;

                dp[row][col] = down + right ;
            }
        }
        return dp[0][0] ;
    }

//  Memoization 
int solveMemo(int row, int col, vector<vector<int>>& dp){
	if(row == 0 && col == 0){
		return 1 ;
	}
	if(row < 0 || col < 0)
		return 0 ;
	
	if(dp[row][col] != -1){
		return dp[row][col] ;
	}
	return dp[row][col] = solveMemo(row, col-1, dp) + solveMemo(row-1, col, dp) ;
}
int uniquePaths(int m, int n){
	vector<vector<int>> dp(m, vector<int>(n, -1)) ;
	return solveMemo(m-1, n-1, dp);
}

// Recursion
// Approach - 1 
int uniquePaths(int m, int n) {
	if(m == 1 && n == 1){
		return 1 ;
	}
	if(m == 1)
		return uniquePaths(m, n-1) ;
	
	if(n == 1)
		return uniquePaths(m-1, n) ;
	
	return uniquePaths(m, n-1) + uniquePaths(m-1, n) ;
}

// Approach - 2
// 1-based indexing
int uniquePaths(int m, int n) {
	if(m == 1 && n == 1){
		return 1 ;
	}
	if(m < 1 || n < 1)
		return 0 ;
	
	return uniquePaths(m, n-1) + uniquePaths(m-1, n) ;
}