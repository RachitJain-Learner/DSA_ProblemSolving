DP 41. Longest Increasing Subsequence

class Solution {
public:
    // Recursion
    int solve(int ind, int prevInd, vector<int>& nums){

        if(ind == nums.size())  return 0 ;

        int exclude = solve(ind+1, prevInd, nums) ;

        int include = 0 ;
        if(prevInd == -1 || nums[prevInd] < nums[ind]){
            include = 1 + solve(ind+1, ind, nums) ;
        }
        return max(include, exclude) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums);
    }

    // Memoization
    int solve(int ind, int prevInd, vector<int>& nums, vector<vector<int>>& dp){

        if(ind == nums.size())  return 0 ;

        if(dp[ind][prevInd+1] != -1){
            return dp[ind][prevInd+1] ;
        }
        int exclude = solve(ind+1, prevInd, nums, dp) ;

        int include = 0 ;
        if(prevInd == -1 || nums[prevInd] < nums[ind]){
            include = 1 + solve(ind+1, ind, nums, dp) ;
        }
        return dp[ind][prevInd+1] = max(include, exclude) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<int>> dp(n, vector<int>(n+1, -1)) ;
        return solve(0, -1, nums, dp);
    }

    // Tabulation
    int solve(vector<int>& nums){
        int n = nums.size() ;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)) ;
      
        for(int ind = n-1 ; ind >= 0 ; ind--){  
            for(int prevInd= n-1 ; prevInd>= -1 ; prevInd--){   //ind-1
                int exclude = dp[ind+1][prevInd+1] ;    //Increase 2nd index + 1 in dp[][ +1] everywhere
                int include = 0 ;
                if(prevInd == -1 || nums[prevInd] < nums[ind]){
                    include = 1 + dp[ind+1][ind+1] ;
                }
                dp[ind][prevInd+1] = max(include, exclude) ;
            }
        }
        return dp[0][0] ;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }

    // Space Optimisation
    int solve(vector<int>& nums){
        int n = nums.size() ;
        vector<int> prev(n+1, 0), curr(n+1, 0) ;
      
        for(int ind = n-1 ; ind >= 0 ; ind--){  
            for(int prevInd= n-1 ; prevInd>= -1 ; prevInd--){   //ind-1
                int exclude = prev[prevInd+1] ;    //Increase 2nd index + 1 in dp[][ +1] everywhere
                int include = 0 ;
                if(prevInd == -1 || nums[prevInd] < nums[ind]){
                    include = 1 + prev[ind+1] ;
                }
                curr[prevInd+1] = max(include, exclude) ;
            }
            prev = curr ;
        }
        return prev[0] ;
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};