// Longest Common Subsequence | (DP - 25)


class Solution {
public:
    //  Space Optimisation 
    int solveSpace(string &a, string &b) {
        int m = a.length() ;
        int n = b.length() ;

        vector<int> prev(n+1, 0) ;
        vector<int> curr(n+1, 0) ;

        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                int ans = 0 ;
                if(a[i-1] == b[j-1])
                    ans = 1 + prev[j-1] ;
                else{
                    int ans1 = curr[j-1] ; 
                    int ans2 = prev[j] ;

                    ans = max(ans1, ans2) ;
                }
                curr[j] = ans ;
            }
            prev = curr ;
        }
        return prev[n] ;   
    }
    int longestCommonSubsequence(string &a, string &b) {
        return solveSpace(a, b);
    }

    // Tabulation
    int solveTab(string &a, string &b) {
        int m = a.length() ;
        int n = b.length() ;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)) ;

        for(int i=0 ; i<=m ; i++){
            for(int j=0 ; j<=n ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0 ;
                }
            }
        }

        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                int ans = 0 ;
                if(a[i-1] == b[j-1])
                    ans = 1 + dp[i-1][j-1] ;
                else{
                    int ans1 = dp[i][j-1] ; 
                    int ans2 = dp[i-1][j] ;

                    ans = max(ans1, ans2) ;
                }
                dp[i][j] = ans ;
            }
        }
        return dp[m][n] ;
    }
    int longestCommonSubsequence(string &a, string &b) {
        
        return solveTab(a, b);
    }

    // Recursion + Memoization
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        if(i< 0 || j < 0)
            return 0 ;
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        int ans = 0 ;
        if(a[i] == b[j])
            ans = 1 + solve(a, b, i-1, j-1, dp);
        else{
            int ans1 = solve(a, b, i, j-1, dp) ;
            int ans2 = solve(a, b, i-1, j, dp) ;

            ans = max(ans1, ans2) ;
        }
        return dp[i][j] = ans ;
    }
    int longestCommonSubsequence(string &a, string &b) {
        vector<vector<int>> dp(a.length(), vector<int>(b.length(), -1)) ;
        return solve(a, b, a.length()-1, b.length()-1, dp);
    }

    // Recursion
    int solve(string &a, string &b, int i, int j) {
        if(i< 0 || j < 0)
            return 0 ;


        if(a[i] == b[j])
            return 1 + solve(a, b, i-1, j-1);
        
        int ans1 = solve(a, b, i, j-1) ;
        int ans2 = solve(a, b, i-1, j) ;

        return max(ans1, ans2) ;
        
    }
    int longestCommonSubsequence(string &a, string &b) {
        return solve(a, b, a.length()-1, b.length()-1);
    }

};