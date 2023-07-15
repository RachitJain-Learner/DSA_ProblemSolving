// Coin Change 2 (DP - 22)
// In such target problems, declare dp[ind][targ] ie. target should be second index 

class Solution {
public:
    // Space Optimisation
    int solve(int amount, vector<int>& coins){
        int n = coins.size() ;
        vector<int> prev(amount+1, 0), curr(amount+1, 0) ;
        
        prev[0] = 1 ;   // not needed
        curr[0] = 1 ;
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int target= 1 ; target <= amount ; target++){
                int nottake = prev[target]  ;
        
                int take = 0;
                if(target >= coins[ind]){
                    take = curr[target-coins[ind]] ;
                }
                curr[target] = take + nottake ;
            }
            prev = curr ;
        }
        return prev[amount] ;
    }
    int change(int amount, vector<int>& coins) {
        return solve(amount, coins) ;
    }

    // Tabulation
    int solve(int amount, vector<int>& coins){
        int n = coins.size() ;
        vector<vector<int>> dp(amount+1, vector<int>(n+1, 0)) ;
        
        for(int i=0 ; i<= n ; i++){
            dp[0][i] = 1 ;
        }
        
        for(int target= 1 ; target <= amount ; target++){
            for(int ind = n-1 ; ind >= 0 ; ind--){
                int nottake = dp[target][ind+1]  ;
        
                int take = 0;
                if(target >= coins[ind]){
                    take = dp[target-coins[ind]][ind] ;
                }
                dp[target][ind] = take + nottake ;
            }
        }
        return dp[amount][0] ;
    }

    int change(int amount, vector<int>& coins) {
        return solve(amount, coins) ;
    }

    //  Recursion + Memoization
    int solve(int target, int ind, vector<int>& coins, vector<vector<int>>& dp){
        if(target == 0){
            return 1 ;
        }
        if(ind == coins.size())
            return 0 ;

        if(dp[target][ind] != -1)
            return dp[target][ind] ;

        int nottake = solve(target, ind+1, coins, dp) ;
        
        int take = 0;
        if(target >= coins[ind]){
            take = solve(target-coins[ind], ind, coins, dp) ;
        }
        return dp[target][ind] = take + nottake ;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;

        vector<vector<int>> dp(amount+1, vector<int>(n+1, -1)) ;
        return solve(amount, 0, coins, dp) ;
    }
};