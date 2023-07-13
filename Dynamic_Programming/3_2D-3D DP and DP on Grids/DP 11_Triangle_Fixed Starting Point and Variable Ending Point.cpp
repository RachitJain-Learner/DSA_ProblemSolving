// DP 11. Triangle | Fixed Starting Point and Variable Ending Point 

#include <bits/stdc++.h> 

// Space Optimisation
int solveSpaceOptim(vector<vector<int>>& triangle, int n){
	vector<int> prev(n, 0);
	vector<int> curr(n, 0);

	for(int i=0 ; i<= n-1 ; i++){
		prev[i] = triangle[n-1][i] ;
	}

	for(int row= n-2 ; row >= 0 ; row--){
		for(int col = row ; col >= 0 ; col--){
			int down = prev[col] ;
			int diag = prev[col+1] ;

			curr[col] = triangle[row][col] + min(down, diag) ;
		}
		prev = curr ;
	}
	return prev[0] ;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solveSpaceOptim(triangle, n) ;
}


// Tabulation - Bottom Up Approach
int solveTab(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int i=0 ; i<= n-1 ; i++){
		dp[n-1][i] = triangle[n-1][i] ;
	}
	for(int row= n-2 ; row >= 0 ; row--){
		for(int col = row ; col >= 0 ; col--){
			int down = dp[row+1][col] ;
			int diag = dp[row+1][col+1] ;

			dp[row][col] = triangle[row][col] + min(down, diag) ;
		}
	}
	return dp[0][0] ;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solveTab(triangle, n) ;
}


// Recursion + Memoization
int solve(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
	if(row == n-1 && col <= n-1){
		return triangle[row][col] ;
	}
	if(dp[row][col] != -1){
		return dp[row][col] ;
	}

	int down = solve(row+1, col, triangle, n, dp) ;
	int diag = solve(row+1, col+1, triangle, n, dp) ;

	return dp[row][col] = triangle[row][col] + min(down, diag) ;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){

	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(0, 0, triangle, n, dp) ;
}


// Recursion

int solve(int row, int col, vector<vector<int>>& triangle, int n){
	if(row == n-1 && col <= n-1){
		return triangle[row][col] ;
	}

	int down = solve(row+1, col, triangle, n) ;
	int diag = solve(row+1, col+1, triangle, n) ;

	return triangle[row][col] + min(down, diag) ;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solve(0, 0, triangle, n) ;
}
