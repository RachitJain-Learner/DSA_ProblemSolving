Buy and Sell Stocks With Transaction Fee|(DP-40)

class Solution {
public:
    // Recursion + Memoization
    int solve(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        int n = prices.size() ;
        if(ind == n)  return 0 ;
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy] ;
        }
        int maxProfit = 0 ;
        if(buy){
            maxProfit = max(-prices[ind] - fee + solve(ind+1, 0, prices, fee, dp), solve(ind+1, 1, prices, fee, dp)) ;
        }
        else{
            maxProfit = max(prices[ind] + solve(ind+1, 1, prices, fee, dp), solve(ind+1, 0, prices, fee, dp)) ;
        }
        return dp[ind][buy] = maxProfit ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>> dp(n, vector<int>(2, -1)) ;
        return solve(0, 1, prices, fee, dp) ;
    }

    // Tabulation
    int solve(vector<int>& prices, int fee){
        int n = prices.size() ;
        vector<vector<int>> dp(n+1, vector<int>(2, 0)) ;
        
        for(int ind = n-1 ; ind>= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int maxProfit = 0 ;
                if(buy){
                    maxProfit = max(-prices[ind] - fee + dp[ind+1][0], dp[ind+1][1]) ;
                }
                else{
                    maxProfit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]) ;
                }
                dp[ind][buy] = maxProfit ;
            }
        }
        return dp[0][1] ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee) ;
    }

    // Space Optimisation
    int solve(vector<int>& prices, int fee){
        int n = prices.size() ;
        
        vector<int> prev(2, 0) ;
        vector<int> curr(2, 0) ;

        for(int ind = n-1 ; ind>= 0 ; ind--){
            for(int buy = 0 ; buy < 2 ; buy++){
                int maxProfit = 0 ;
                if(buy){
                    maxProfit = max(-prices[ind] - fee + prev[0], prev[1]) ;
                }
                else{
                    maxProfit = max(prices[ind] + prev[1], prev[0]) ;
                }
                curr[buy] = maxProfit ;
            }
            prev = curr ;
        }
        return curr[1] ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee) ;
    }
};