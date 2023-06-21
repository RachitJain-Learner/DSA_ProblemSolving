Buy and Stock Sell IV |(DP-38) --> Atmost K Transactions

#include <bits/stdc++.h> 

// Tabulation - 3D DP
int solve(vector<int>& prices, int n, int k){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0))) ;
    
    for(int ind = n-1 ; ind >= 0; ind--){
        for(int buy = 0; buy <= 1 ; buy++){
            for(int trxns = 1 ; trxns <= k ; trxns++){
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
    return dp[0][1][k] ;
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    return solve(prices, n, k);
}
