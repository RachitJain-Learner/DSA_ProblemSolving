//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solveMemo(int W, int *wt, int *val, int n, vector<vector<int>>& dp){
        if(n == 0){
            if(W >= wt[0])
                return val[0];
                
            return 0 ;
        }
        if(dp[W][n] != -1){
            return dp[W][n] ;
        }
        
        int take = 0 ;
        if(W-wt[n] >= 0)
            take =  val[n] + solveMemo(W-wt[n], wt, val, n-1, dp);
            
        int nottake = 0 + solveMemo(W, wt, val, n-1, dp);
        
        return dp[W][n] = max(take, nottake) ;
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   return solveRec(W, wt, val, n-1);
        
        vector<vector<int>> dp(W+1, vector<int>(n, -1));
        return solveMemo(W, wt, val, n-1, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends