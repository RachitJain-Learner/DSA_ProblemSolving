// Knapsack with Duplicate Items - Unbounded Knapsack (DP - 23)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Recursion
    int solve(int N, int W, int val[], int wt[])
    {
        if(W == 0){   //  Problem similar to Minimum coins
            return 0 ;
        }
        if(W < 0){
            return -1;
        }
        int maxProfit = 0 ;
        
        for(int ind = 0; ind<=N; ind++){
            
            int ans = solve(N, W-wt[ind], val, wt) ; 
            if(ans != -1)
                maxProfit = max(maxProfit, val[ind] + ans) ;
        }
        return maxProfit ;
    }

    int knapSack(int N, int W, int val[], int wt[])
    {   
        return solve(N-1, W, val, wt) ;
    }
    
    // Memoization
    int solveMemo(int N, int W, int val[], int wt[], vector<int>& dp)
    {
        if(W == 0){   //  Problem similar to Minimum coins
            return 0 ;
        }
        if(W < 0){
            return INT_MIN;
        }
        
        if(dp[W] != -1)
            return dp[W] ;
            
        int maxProfit = 0 ;
        
        for(int ind = 0; ind<=N; ind++){
            
            int ans = solveMemo(N, W-wt[ind], val, wt, dp) ; 
            if(ans != INT_MIN)
                maxProfit = max(maxProfit, val[ind] + ans) ;
        }
        return dp[W] = maxProfit ;
    }

    int knapSack(int N, int W, int val[], int wt[])
    {   
        vector<int> dp(W+1, -1);
        return solveMemo(N-1, W, val, wt, dp) ;
    }
    
    // Tabulation with space optimised
    int solveTab(int N, int W, int val[], int wt[])
    {
        vector<int> dp(W+1, 0);
        
        for(int i=0 ; i<=W ; i++){
            int maxProfit = 0 ;
        
            for(int ind = 0; ind<=N; ind++){
                
                if(i-wt[ind] >= 0){
                    int ans = dp[i-wt[ind]] ;    //solveMemo(N, W-wt[ind], val, wt, dp) ; 
                    maxProfit = max(maxProfit, val[ind] + ans) ;
                }
            }
            dp[i] = maxProfit ;
        } 
        return dp[W] ;
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {   
        return solveTab(N-1, W, val, wt) ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends