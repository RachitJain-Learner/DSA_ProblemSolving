Count Partitions with Given Difference (DP - 18)

#include <bits/stdc++.h> 
int mod = 1e9+7 ;

// Tabulation
int CountSubsetSumTarget(vector<int> &arr, int n, int sum){
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    dp[n][0] = 1 ;

    for(int ind=n-1 ; ind>= 0 ; ind--){
        for(int targ=0; targ <= sum; targ++){
            int exclude = dp[ind+1][targ] ;
            int include = 0;
            if(arr[ind] <= targ){
                include = dp[ind+1][targ-arr[ind]] ;
            }
            dp[ind][targ] = include % mod + exclude % mod ;
        }
    }
    return dp[0][sum] % mod;
}

// Space Optimisation
int CountSubsetSumTarget(vector<int> &arr, int n, int sum){
        vector<int> prev(sum+1, 0);
        vector<int> curr(sum+1, 0);
    
        prev[0] = 1 ;
    
        for(int ind=n-1 ; ind>= 0 ; ind--){
            for(int targ=0; targ <= sum; targ++){
                int exclude = prev[targ] ;
                int include = 0;
                if(arr[ind] <= targ){
                    include = prev[targ-arr[ind]] ;
                }
                curr[targ] = include % mod + exclude % mod ;
            }
            prev = curr ;
        }
        return prev[sum] % mod;
    }

int countPartitions(int n, int d, vector<int> &arr){
    int sum = 0 ;
    for(int i=0 ; i < n ; i++)  sum += arr[i] ;

    // Edge Case
    if((sum-d)< 0 || (sum-d) & 1)   
        return 0 ;

    // Looking for Target = (sum-d)/2 ;
    return CountSubsetSumTarget(arr, n, (sum-d)/2) % mod;
}