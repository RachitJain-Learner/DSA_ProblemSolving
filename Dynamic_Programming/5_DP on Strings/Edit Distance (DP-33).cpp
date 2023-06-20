class Solution {
public:
    
    // Memoization
    int solve(string &word1, string &word2, int n1, int n2, vector<vector<int>> &dp){
        if(n1 < 0)
            return n2+1 ;
        if(n2 < 0)
            return n1+1;
            
        if(dp[n1][n2] != -1) 
            return dp[n1][n2] ;

        int ans = 0 ;
        if(word1[n1] == word2[n2]){
            return dp[n1][n2] = solve(word1, word2, n1-1, n2-1, dp) ;
        }
        else{
            int insertAns = 1 + solve(word1, word2, n1, n2-1, dp) ;

            int delAns = 1 + solve(word1, word2, n1-1, n2, dp) ;

            int replaceAns = 1 + solve(word1, word2, n1-1, n2-1, dp) ;

            ans = min(insertAns, min(delAns, replaceAns)) ;
        }
        return dp[n1][n2] = ans ;
    }

    // Tabulation --> Changing of indexing 
    int solveTab(string &word1, string &word2){
        int n1 = word1.length(), n2 = word2.length() ; 
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0)) ;

        for(int i= 0 ; i <= n1 ; i++){
            dp[i][0] = i  ;
        }
        for(int j=0 ; j<= n2 ; j++){
            dp[0][j] = j  ;   
        }
            
        for(int i= 1 ; i<= n1 ; i++){
            for(int j = 1 ; j <= n2 ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] ;
                }
                else{
                    int insertAns = 1 + dp[i][j-1] ;

                    int delAns = 1 + dp[i-1][j] ;

                    int replaceAns = 1 + dp[i-1][j-1] ;

                    dp[i][j] = min(insertAns, min(delAns, replaceAns)) ;
                }
            }
        }
        return dp[n1][n2] ; 
    }
    int minDistance(string word1, string word2) {

       return solveTab(word1, word2) ;
    }

    // Space Optimisation
    int solveSpace(string &word1, string &word2){
        int n1 = word1.length(), n2 = word2.length() ; 
        
        vector<int> prev(n2+1, 0), curr(n2+1, 0) ;
        
        for(int j=0 ; j<= n2 ; j++){
            prev[j] = j  ;   
        }
            
        for(int i= 1 ; i<= n1 ; i++){
            curr[0] = i  ;

            for(int j = 1 ; j <= n2 ; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1] ;
                }
                else{
                    int insertAns = 1 + curr[j-1] ;

                    int delAns = 1 + prev[j] ;

                    int replaceAns = 1 + prev[j-1] ;

                    curr[j] = min(insertAns, min(delAns, replaceAns)) ;
                }
            }
            prev = curr ;
        }
        return prev[n2] ; 
    }
    int minDistance(string word1, string word2) {
        return solveSpace(word1, word2) ;
    }

};