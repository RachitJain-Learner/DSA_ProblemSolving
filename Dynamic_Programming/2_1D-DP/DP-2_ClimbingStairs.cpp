// https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// Count ways to reach the n'th stair

#include<bits/stdc++.h>
using namespace std;

# define mod 1000000007

class Solution
{   
    public:
    // Space Optimization
    int solve(int n){
            
        int prev2 = 1 ;     //at 0, only one way from 0 to 0
        int prev1 = 1 ;     //at 1, only one way from 1 to 0
        
        for(int i=2 ; i<=n ; i++){
            int curr = prev1% mod  + prev2% mod ;
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1 ;
    }
        //OR 
    int solve(int n){
        
        if(n == 1)
            return 1;
            
        int prev2 = 1 ;
        int prev1 = 2 ;
        
        for(int i=3 ; i<=n ; i++){
            int curr = prev1% mod  + prev2% mod ;
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return prev1 ;
    }
    int countWays(int n){   
        return solve(n) % mod ;
    }

    // Tabulation
    int solveTab(int n){
        vector<int> dp(n+1, 0);
        
        dp[1] = 1 ;
        dp[2] = 2 ;
        
        for(int i=3; i<=n ; i++){
            dp[i] = dp[i-1]% mod  + dp[i-2]% mod ;
        }
        return dp[n] ;
    }

    int countWays(int n){   
        return solveTab(n) % mod ;
    }

    // Recursion + Memoization

    int solve(int n, vector<int> &dp){
        if(n == 1 || n == 2)
            return n ;
            
        if(dp[n] != -1){
            return dp[n] ;
        }
        return dp[n] = solve(n-1, dp) % mod + solve(n-2, dp) % mod ;
    }

    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {   
        vector<int> dp(n+1, -1);
        return solve(n, dp) % mod ;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends