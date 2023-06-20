//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    public:

    // Tabulation
    int solveTab(int *arr, int n){
        
        vector<int> dp(n, 0);
        
        dp[0] = arr[0] ;
        dp[1] = max(arr[0], arr[1]);
        
        for(int i=2; i< n ; i++){
            int include = arr[i] + dp[i-2];
            
            int exclude = 0 + dp[i-1] ;
            
            dp[i] = max(include, exclude) ;
        }
        return dp[n-1];
    }
    int findMaxSum(int *arr, int n) {
	   return solveTab(arr, n);
	}

    int solveMemo(int *arr, int n, vector<int>& dp){
        if(n == 0)
            return arr[0] ;
        if(n == 1)
            return max(arr[0], arr[1]);
        
        if(dp[n] != -1)
            return dp[n];
            
        int include = arr[n] + solve(arr, n-2, dp) ;
            
        int exclude = 0 + solve(arr, n-1, dp) ;
        
        return dp[n] = max(include, exclude) ;
    }
	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n, -1);
	   return solveMemo(arr, n-1, dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends