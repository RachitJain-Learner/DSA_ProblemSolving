class Solution {
public:
    // Recursion + Memoization
    int solve(vector<int>&prices, int ind, int buy, vector<vector<int>>& dp, int n) {
        if(ind == n){
            return 0 ;  //no option to buy or sell
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy] ;
        }
        
        int maxProfit = 0 ;
        if(buy){
            maxProfit = max(-prices[ind] + solve(prices, ind+1, 0, dp, n), solve(prices, ind+1, 1, dp, n)) ;
        }
        else{
            maxProfit = max(prices[ind] + solve(prices, ind+1, 1, dp, n), solve(prices, ind+1, 0, dp, n)) ;
        }
        return dp[ind][buy] = maxProfit ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp(n+1 ,vector<int>(2, -1)) ;
        return solve(prices, 0, 1, dp, n) ;
    }

    // Tabulation
    int solve(vector<int>&prices, int n) {
        vector<vector<int>> dp(n+1 ,vector<int>(2, 0)) ;
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int maxProfit = 0 ;
                if(buy){
                    maxProfit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1] );
                }
                else{
                    maxProfit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]) ;
                }
                dp[ind][buy] = maxProfit ;
            }
        }
        return dp[0][1] ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        return solve(prices, n) ;
    }

    // Space Optimisation
    int solve(vector<int>&prices, int n) {
        vector<int> prev(2, 0) ;
        vector<int> curr(2, 0) ;

        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int maxProfit = 0 ;
                if(buy){
                    maxProfit = max(-prices[ind] + prev[0], prev[1] );
                }
                else{
                    maxProfit = max(prices[ind] + prev[1], prev[0]) ;
                }
                curr[buy] = maxProfit ;
            }
            prev = curr ;
        }
        return prev[1] ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        return solve(prices, n) ;
    }
};