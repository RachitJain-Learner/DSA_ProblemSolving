//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

# define mod 1000000007

class Solution {
  public:
  
    // Space Optimisation
    long long int solve(long long int n){
        
        int prev1 = 1, prev2 = 1 ;
        
        for(int i=3 ; i<= n ; i++){
            int curr = prev1 % mod + prev2 % mod ; 
            prev1 = prev2 ;
            prev2 = curr ;
        }
        return prev2 % mod ; 
    }
    long long int nthFibonacci(long long int n){
        
        return solve(n);    // Space Optimisation Recursion 
    }
  
    // Tabulation
    long long int solve(long long int n, vector<long long int> &dp){
        
        dp[1] = 1, dp[2] = 1 ;
        
        for(int i=3 ; i<= n ; i++){
            dp[i] = dp[i-1] % mod + dp[i-2] % mod ; //= solve(n-1, dp) % mod + solve(n-2, dp) % mod ;
        }
        
        return dp[n] % mod ; 
    }
    long long int nthFibonacci(long long int n){
         
        return solve(n, dp) % mod ;      // Tabulation
    }
    
    //  Memoization
    long long int solveMemo(long long int n, vector<long long int> &dp){
        if(n == 1 || n == 2){
            return 1 ;
        }
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        return dp[n] = solveMemo(n-1, dp) % mod + solveMemo(n-2, dp) % mod ;
    }
    
    long long int nthFibonacci(long long int n){
        
        vector<long long int> dp(n+1, -1) ;     //Memoization
        
        return solveMemo(n, dp) % mod ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends