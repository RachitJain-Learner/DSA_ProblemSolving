House Robber (DP 6)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    // Space Optimisation
    int solve(int arr[], int n)
    {   
        int prv2 = 0 ;
        int prv1 = arr[0]; //max(arr[0], arr[1]) ;
        
        for(int ind = 1; ind < n ; ind++){
            int take = arr[ind] + prv2 ;
        
            int nottake = 0 + prv1 ;
            
            int curr = max(take, nottake) ;
            prv2 = prv1 ;
            prv1 = curr ;
        }
        return prv1;
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        return solve(arr, n);
    }
    
    //   Tabulation 
    int solve(int arr[], int n)
    {   
        vector<int> dp(n, 0) ;
        dp[0] = arr[0] ;
        dp[1] = max(arr[0], arr[1]) ;
        
        for(int ind = 2; ind < n ; ind++){
            int take = arr[ind] + dp[ind-2] ;
        
            int nottake = 0 + dp[ind-1] ;
            
            dp[ind] = max(take, nottake) ;
        }
        return dp[n-1];
    }
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        return solve(arr, n);
    }
    
    
    //   Recursion + Memoization
    int solve(int nums[], int ind, vector<int>& dp)
    {
        if(ind == 0){
            return nums[0] ;
        }
        // if(ind == 1){
        //     return max(nums[0], nums[1]);
        // }
        // if(ind < 0){
        //     return 0 ;
        // }
        if(dp[ind] != -1){
            return dp[ind] ;
        }
        int take = nums[ind];   
        if(ind > 1) take += solve(nums, ind-2, dp); ;
        
        int nottake = 0 + solve(nums, ind-1, dp) ;
        
        return dp[ind] = max(take, nottake) ;
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n, -1) ;
        return solve(arr, n-1, dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends