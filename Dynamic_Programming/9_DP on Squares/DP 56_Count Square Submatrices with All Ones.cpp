#include <bits/stdc++.h> 

int countSquares(int N, int M, vector<vector<int>> &matrix) {
    
    // Step 1: Create dp array of same size & copy first row and first column
    vector<vector<int>> dp(N, vector<int>(M, 0)) ;

    for(int i=0 ; i<N ; i++)    dp[i][0] = matrix[i][0] ;
    for(int j=0 ; j<M ; j++)    dp[0][j] = matrix[0][j] ;
    
    // Step 2: Fill dp array from prev filled dp array elements
    for(int i=1 ; i<N ; i++){
        for(int j=1 ; j<M ; j++){
            if(matrix[i][j] == 1){
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) ;
            }
        }
    }
    // Step 3: Calculate sum of all index of dp array
    int sum = 0 ;
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<M ; j++){
            sum += dp[i][j] ;
        }
    }
    return sum ;
}