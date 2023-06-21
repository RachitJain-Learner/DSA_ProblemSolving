Minimum Insertions/Deletions to Convert String | (DP- 30)


class Solution {
public:
    // By LCS Approach
    int solveLCS(string word1, string word2){
        int n = word1.length() ;
        int m = word2.length() ;

        vector<int> prev(m+1, 0) ; 
        vector<int> curr(m+1, 0) ;

        // LCS Base Case is at length m, n , it is 0
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j=m-1 ; j >= 0 ; j--){  
                if(word1[i] == word2[j]){
                    curr[j] = 1 + prev[j+1] ;
                }
                else{
                    int op1 = curr[j+1] ; 
                    int op2 = prev[j] ;
                    curr[j] = max(op1, op2) ;
                }
            }
            prev = curr ;
        }
        return prev[0] ;
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        int common = solveLCS(word1, word2) ;
        return (n - common) + (m - common) ;
    }

    // Space Optimisation
    int solve(string word1, string word2){
        int n = word1.length() ;
        int m = word2.length() ;

        vector<int> prev(m+1, 0) ; 
        vector<int> curr(m+1, 0) ;

        for(int j=0 ; j<= m ; j++){
            prev[j] = m-j ;
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            curr[m] = n - i ;       // Every iteration curr array is building
            for(int j=m-1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    curr[j] = prev[j+1] ;
                }
                else{
                    int op1 = curr[j+1] ; 
                    int op2 = prev[j] ;
                    curr[j] = min(op1, op2) + 1 ;
                }
            }
            prev = curr ;
        }
        return curr[0] ;
    }

    //  Tabulation 
    int solve(string word1, string word2){
        int n = word1.length() ;
        int m = word2.length() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;

        for(int j=0 ; j<= m ; j++){
            dp[n][j] = m-j ;
        }
        for(int i=0 ; i<= n ; i++){
            dp[i][m] = n - i ;
        }
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j=m-1 ; j >= 0 ; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1] ;
                }
                else{
                    int op1 = dp[i][j+1] ; 
                    int op2 = dp[i+1][j] ;
                    dp[i][j] = min(op1, op2) + 1 ;
                }
            }
        }
        return dp[0][0] ;
    } 
    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        return solve(word1, word2) ;
    }

    // Recursion + Memoization
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& dp){
        int n = word1.length() ;
        int m = word2.length() ;

        if(i == n){
            return m - j ;
        }
        if(j == m){
            return n - i ;
        }
        if(dp[i][j] != -1)
            return dp[i][j] ;

        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1, dp) ;
        }
        else{
            int op1 = solve(word1, word2, i, j+1, dp) ;
            int op2 = solve(word1, word2, i+1, j, dp) ;

            return dp[i][j] = min(op1, op2) + 1 ;
        }
        return 0 ;
    } 

    int minDistance(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)) ;
        return solve(word1, word2, 0, 0, dp) ;
    }
};