// DP 21. Target Sum 

// Failed Approach Explanation at last
// Right Approach - DP.17+18 Count Partitions with Given Difference = Target

#include <bits/stdc++.h> 

// Space Optimisation
int spaceOptimisation(int target, vector<int>& arr, int n){    
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1 ;
    
    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int val=0 ; val<=target ; val++){
            int include = 0 ;
            if(val >= arr[ind]) 
                include = prev[val-arr[ind]] ;
            
            int exclude = prev[val] ;

            curr[val] = include + exclude ;
        }
        prev = curr ;
    }
    return curr[target] ;
}

// Tabulation
int solveTab(int target, vector<int>& arr, int n){
    
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[n][0] = 1 ;
    
    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int val=0 ; val<=target ; val++){
            int include = 0 ;
            if(val >= arr[ind]) 
                include = dp[ind+1][val-arr[ind]] ;
            
            int exclude = dp[ind+1][val] ;

            dp[ind][val] = include + exclude ;
        }
    }
    return dp[0][target] ;
}

int targetSum(int n, int target, vector<int>& arr) {

    int totSum = 0 ;
    for(auto it: arr){
        totSum += it ;
    }
    // subset sum can't be negative or in decimal
    if(totSum-target < 0 || (totSum-target) % 2)
        return 0 ;

    int value = (totSum-target)/2 ;
    
    return solveTab(value, arr, n);
    return spaceOptimisation(value, arr, n);
}


// Recursion + Memoization
int solve(int ind, int val, vector<int>& arr, int n, vector<vector<int>>& dp){
    if(ind == n)
        return val == 0 ;
    
    if(dp[ind][val] != -1){
        return dp[ind][val] ;
    }
    int include = 0 ;
    if(val >= arr[ind]) 
        include = solve(ind+1, val-arr[ind], arr, n, dp);
    
    int exclude = solve(ind+1, val, arr, n, dp);

    return dp[ind][val] = include + exclude ;
}
int targetSum(int n, int target, vector<int>& arr) {

    int totSum = 0 ;
    for(auto it: arr){
        totSum += it ;
    }
    // subset sum can't be negative or in fraction
    if(totSum-target < 0 || (totSum-target) % 2)
        return 0 ;

    int value = (totSum-target)/2 ;
    vector<vector<int>> dp(n+1, vector<int>(value+1, -1));
    
    return solve(0, value, arr, n, dp);
}


//   ******* Learning - Very IMP *******
/*  // Recursion- TLE but correct answer
    // applying memoization is going out of index because val+arr[ind] is going out of bound of dp array
int solve(int ind, int val, vector<int>& arr, int n){
    if(val == 0 && ind == n)
        return 1 ;
    
    if(ind >= n){
        return 0 ;
    }
    int add = solve(ind+1, val-arr[ind], arr, n);
    int subt = solve(ind+1, val+arr[ind], arr, n);

    return add + subt ;
}
int targetSum(int n, int target, vector<int>& arr) {
    return solve(0, target, arr, n);
}
*/
/*
// This memoized code doesn't work because val+arr[ind] is going out of bound of dp array
int solve(int ind, int val, vector<int>& arr, int n, vector<vector<int>>& dp){
    if(val == 0 && ind == n)
        return 1 ;
    
    if(ind >= n){
        return 0 ;
    }
    if(dp[ind][val] != -1){
        return dp[ind][val] ;
    }
    int add = 0 ;
    if(val >= arr[ind])solve(ind+1, val-arr[ind], arr, n, dp);
    int subt = solve(ind+1, val+arr[ind], arr, n, dp);

    return dp[ind][val] = add + subt ;
}
int targetSum(int n, int target, vector<int>& arr) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    return solve(0, target, arr, n, dp);
}
*/