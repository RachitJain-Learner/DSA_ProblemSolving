Count Subsets with Sum K (DP - 17)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	
    // Space Optimisation
    int solveSpace(int nums[], int n, int sum)
    {   
        vector<int> prev(sum+1, 0) ; 
        vector<int> curr(sum+1, 0) ;
        prev[0] = 1 ;
        
        for(int ind=n-1 ; ind >= 0 ; ind--){
            for(int target=0 ; target <= sum ; target++){
                int include = 0;
                if(target >= nums[ind])
                    include = prev[target-nums[ind]] ;
            
                int exclude = prev[target] ;
                
                curr[target] = include% mod + exclude% mod ;
            }
            prev = curr ;
        }
        return prev[sum] ;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        return solveSpace(arr, n, sum)% mod;
	}

    // Tabulation
	int solveTab(int nums[], int n, int sum)
    {   
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        dp[n][0] = 1 ;
        
        for(int ind=n-1 ; ind >= 0 ; ind--){
            for(int target=0 ; target <= sum ; target++){
                int include = 0;
                if(target >= nums[ind])
                    include = dp[ind+1][target-nums[ind]] ;
            
                int exclude = dp[ind+1][target] ;
                
                dp[ind][target] = include% mod + exclude% mod ;
            }
        }
        return dp[0][sum] ;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        return solveTab(arr, n, sum)% mod;
	}

    // Memoization-1: from 0 to n
	int solveMemo(int nums[], int target, int ind, int n, vector<vector<int>>& dp)
    {
        if(ind == n){
            return target == 0  ;
        }
        if(dp[target][ind] != -1){
            return dp[target][ind] % mod ;
        }
    
        int include = 0;
        if(target >= nums[ind])
            include = solveMemo(nums, target-nums[ind], ind+1, n, dp);
    
        int exclude = solveMemo(nums, target, ind+1, n, dp);
        
        return dp[target][ind] = include % mod + exclude % mod ;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(sum+1, vector<int>(n, -1));
        return solveMemo(arr, sum, 0, n, dp)% mod;
	}
	
	// Memoization-2: from n-1 to 0
	int mod = 1e9+7;
    int func(int ind,int sum,int arr[],vector<vector<int>>&dp){
        
        if(ind < 0) return sum == 0 ;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        int pick = 0;
        if(arr[ind] <= sum){
            pick = func(ind-1,(sum-arr[ind])%mod,arr,dp)%mod;
        }
        int notPick = func(ind-1,sum%mod,arr,dp)%mod;
        
        return dp[ind][sum] = (pick%mod + notPick%mod)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp)%mod;
	}
};

//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";	     
    }
    return 0;
}

// } Driver Code Ends