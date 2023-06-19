//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // Tabulation with Space Optimised 
    int solveTab(int *price, int len){
        
        vector<int> dp(len+1, 0) ;
        
        for(int j=1 ; j<=len ; j++){
            int maxPrice = INT_MIN ;
        
            for(int i=0 ; i<j ; i++){
                int ans = price[i] + dp[j-i-1];
    
                maxPrice = max(maxPrice, ans) ;
            }
            dp[j] = maxPrice ;
        }
        return dp[len];
    }
    int cutRod(int price[], int n) {
        
        return solveTab(price, n);
    }

    // Memoization
    int solveMemo(int *price, int len, vector<int>& dp){
        if(len <= 0){   // len<0 not needed since i is restricted to max of len & will never
            return 0 ;  // be greater than len so it will never exceed len or never become negative
        }
        if(dp[len] != -1){
            return dp[len] ;
        }
        
        int maxPrice = INT_MIN ;
        
        for(int i=0 ; i<len ; i++){
            int ans = price[i] + solveMemo(price, len-i-1, dp);

            maxPrice = max(maxPrice, ans) ;
        }
        return dp[len] = maxPrice ;
    }
    int cutRod(int price[], int n) {
        
        vector<int> dp(n+1, -1);
        return solveMemo(price, n, dp);
    }
    
    // Recursion --> TLE
    int solve(int *price, int len){
        if(len == 0){   
            return 0 ;  
        }
        
        int maxPrice = INT_MIN ;
        
        for(int i=0 ; i<len ; i++){
            int ans = price[i] + solve(price, len-i-1);

            maxPrice = max(maxPrice, ans) ;
        }
        return maxPrice ;
    }
    
    int cutRod(int price[], int n) {
        
        return solve(price, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends