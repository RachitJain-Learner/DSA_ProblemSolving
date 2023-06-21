#include <bits/stdc++.h> 

// Tabulation
int solve(vector<int>& prices, int n){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))) ;
    
    for(int ind = n-1 ; ind >= 0; ind--){
        for(int buy = 0; buy <= 1 ; buy++){
            for(int trxns = 1 ; trxns <= 2 ; trxns++){
                int profit = 0 ;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0][trxns], dp[ind+1][1][trxns]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1][trxns-1], dp[ind+1][0][trxns]);
                }
                dp[ind][buy][trxns] = profit ;
            }
        }
    }
    return dp[0][1][2] ;
}
int maxProfit(vector<int>& prices, int n)
{   
    return solve(prices, n);
}

// Recursion + Memoization
int solve(int ind, int buy, int trxns, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
    if(trxns == 0 || ind == n)  return 0 ;

    if(dp[ind][buy][trxns] != -1){
        return dp[ind][buy][trxns] ;
    }
    int profit = 0 ;
    if(buy){
        profit = max(-prices[ind] + solve(ind+1, 0, trxns, prices, n, dp),
            solve(ind+1, 1, trxns, prices, n, dp));
    }
    else{
        profit = max(prices[ind] + solve(ind+1, 1, trxns-1, prices, n, dp),
            solve(ind+1, 0, trxns, prices, n, dp));
    }
    return dp[ind][buy][trxns] = profit ;
}
int maxProfit(vector<int>& prices, int n)
{   
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1))) ;
    return solve(0, 1, 2, prices, n, dp);
}
