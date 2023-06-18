class Solution {
    public:

    // Recursion + Memoization
    int solve(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0)
            return 0 ;
        if(amount < 0){
            return INT_MAX ;
        }
        if(dp[amount] != -1){
            return dp[amount] ;
        }

        int minCoins = INT_MAX ;

        for(int i=0; i<coins.size() ; i++){
            int tempAns = solve(amount-coins[i], coins, dp) ;

            if(tempAns != INT_MAX){
                minCoins = min(minCoins, 1 + tempAns);
            }   
        }
        return dp[amount] = minCoins ;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(amount, coins, dp) ;     // Recursion + Memo

        return (ans == INT_MAX) ? -1 : ans ; 
    }

    // Tabulation
    int solveTab(int n, vector<int> &coins){
        vector<int> dp(n+1, 0);

        for(int t=1 ; t<= n ; t++){
            int minCoins = INT_MAX ;

            for(int i=0; i<coins.size() ; i++){
                if(t-coins[i] >= 0){
                    int tempAns = dp[t-coins[i]] ;

                    if(tempAns != INT_MAX){
                        minCoins = min(minCoins, 1 + tempAns);
                    }   
                }
            }
            dp[t] = minCoins ;
        }
        return dp[n] ;
    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = solveTab(amount, coins) ;
        return (ans == INT_MAX) ? -1 : ans ; 
    }
};