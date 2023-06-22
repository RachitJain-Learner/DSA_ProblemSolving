Distinct Subsequences| (DP-32)

class Solution {
public:

      //Memoization
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        int n= s.length() , m= t.length() ;

        if(j == m)  return 1;
        if(i == n)  return 0 ;

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        if(s[i] == t[j])
            return dp[i][j] = solve(i+1, j+1, s, t, dp) + solve(i+1, j, s, t, dp) ;
        
        return dp[i][j] = solve(i+1, j, s, t, dp) ;    
    }
    
    
    int solve(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        int n= s.length() , m= t.length() ;

        if(j == m)  return 1;
        if(i == n)  return 0 ;

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        
        int move = 0 ;
        if(s[i] == t[j])
            move = solve(i+1, j+1, s, t, dp) ;

        int nomove = solve(i+1, j, s, t, dp) ;  

        return dp[i][j] = move + nomove ;
    }

    int numDistinct(string s, string t) {
        int n= s.length() , m= t.length() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)) ;
        return solve(0, 0, s, t, dp) ;
    }
    
    int mod = 1e9+7 ;
    int solve(string &s, string &t){
        int n= s.length() , m= t.length() ;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
        
        for(int i=0 ; i<= n ; i++)   dp[i][m] = 1 ;
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=0 ; j--){
                int move = 0 ;
                if(s[i] == t[j])
                    move = dp[i+1][j+1] % mod;

                int nomove = dp[i+1][j] % mod;

                dp[i][j] = move % mod + nomove % mod;
            }
        }
        return dp[0][0] % mod; 
    }
    int numDistinct(string s, string t) {
        int n= s.length() , m= t.length() ;

        return solve(s, t) ;
    }
    
};