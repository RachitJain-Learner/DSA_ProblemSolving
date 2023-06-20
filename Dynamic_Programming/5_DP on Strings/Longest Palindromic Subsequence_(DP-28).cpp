//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    // By Space Optimisation
    int LongestCommonSubsequence(string A, string B){
        
        int n = A.length(), m = B.length() ;
        vector<int> prev(m+1), curr(m+1, 0);
        
        int ans = 0 ;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(A[i] == B[j]){
                    ans = 1 + prev[j+1] ;
                }
                else{
                    ans = max(curr[j+1], prev[j]) ;
                }
                curr[j] = ans ;
            }
            prev = curr ;
        }
        return prev[0] ;
    }

    // By Tabulation
    int LongestCommonSubsequence(string A, string B){
        
        int n = A.length(), m = B.length() ;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)) ;
        
        int ans = 0 ;
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(A[i] == B[j]){
                    ans = 1 + dp[i+1][j+1] ;
                }
                else{
                    ans = max(dp[i][j+1], dp[i+1][j]) ;
                }
                dp[i][j] = ans ;
            }
        }
        return dp[0][0] ;
    }
    int longestPalinSubseq(string A) {
        string B = A ;
        reverse(A.begin() , A.end()) ;
        
        return LongestCommonSubsequence(A, B) ;
    }
};

//{ Driver Code Starts.
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// } Driver Code Ends