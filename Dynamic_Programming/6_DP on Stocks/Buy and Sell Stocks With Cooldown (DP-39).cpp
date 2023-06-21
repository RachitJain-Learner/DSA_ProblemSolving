Buy and Sell Stocks With Cooldown|(DP-39)
// with only change on day to buy stock ie. ind+2, hence size of dp array increases to n+2

#include <bits/stdc++.h> 

// Tabulation 
int solve(vector<int>&prices, int n) {
    vector<vector<int>> dp(n+2 ,vector<int>(2, 0)) ;
    
    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0 ; buy < 2 ; buy++){
            int maxProfit = 0 ;
            if(buy){
                maxProfit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1] );
            }
            else{
                maxProfit = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]) ;
            }
            dp[ind][buy] = maxProfit ;
        }
    }
    return dp[0][1] ;
}
int stockProfit(vector<int> &prices){
    int n = prices.size() ;
    return solve(prices, n) ;
}