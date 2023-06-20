// Partition Equal Subset Sum (DP- 15)
// Problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //   Recursion
    int SubsetSumTarget(int ind, int targ, int arr[]){
        if(targ == 0)   return 1 ;
        if(ind == 0) targ == arr[0] ;
        
        int exclude = SubsetSumTarget(n-1, targ , arr) ;
        
        int include = 0 ;
        if(arr[n] <= targ){
            include = SubsetSumTarget(n-1, targ-arr[n] , arr) ;
        }
        
        return include || exclude ;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i< N ; i++)
            sum += arr[i] ;
            
        if(sum % 2)     //  odd sum cannot be divided into two halves
            return false ;

        return SubsetSumTarget(N-1, sum/2, arr) ;
    }

    // Memoization
    int SubsetSumTarget(int n, int targ, int arr[], vector<vector<int>>& dp){
        
        if(targ == 0)   return 1 ;
        
        if(n == 0) 
            return targ == arr[0] ;
        
        if(dp[n][targ] != -1){
            return dp[n][targ] ;
        }
        
        int exclude = SubsetSumTarget(n-1, targ , arr, dp) ;
        
        int include = 0 ;
        if(arr[n] <= targ){
            include = SubsetSumTarget(n-1, targ-arr[n] , arr, dp) ;
        }
        return dp[n][targ] = exclude || include ;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i= 0; i< N ; i++)
            sum += arr[i] ;
            
        if(sum % 2 == 1)
            return false ;
        
        int amt = sum / 2 ;
        vector<vector<int>> dp(N, vector<int>(amt+1, -1)) ;
        
        return SubsetSumTarget(N-1, amt, arr, dp) ;
    }
    
    // Tabulation
    int SubsetSumTarget(int n, int amount, int arr[]){
        
        vector<vector<int>> dp(n, vector<int>(amount+1, 0)) ;
        
        for(int i=0 ; i<n ; i++){
            dp[i][0] = 1 ;
        }
        
        if(arr[0] <= amount){
            dp[0][arr[0]] = 1 ;
        }
        
        for(int ind = 1 ; ind < n ; ind++){
            for(int targ = amount ; targ >= 1 ; targ--){
                int exclude = dp[ind-1][targ] ;
        
                int include = 0 ;
                if(arr[ind] <= targ){
                    include = dp[ind-1][targ-arr[ind]] ;
                }
                dp[ind][targ] = include || exclude ;
            }
        }
        return dp[n-1][amount]  ;
    }

    // Space Optimisation
    int SubsetSumTarget(int n, int amount, int arr[]){
        
        vector<int> prev(amount+1, 0), curr(amount+1, 0) ;
        prev[0] = curr[0] = 1 ;
        
        if(arr[0] <= amount){
            prev[arr[0]] = 1 ;
        }
        for(int ind = 1 ; ind < n ; ind++){
            for(int targ = amount ; targ >= 1 ; targ--){
                int exclude = prev[targ] ;
        
                int include = 0 ;
                if(arr[ind] <= targ){
                    include = prev[targ-arr[ind]] ;
                }
                curr[targ] = include || exclude ;
            }
            prev = curr ;
        }
        return prev[amount]  ;
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i< N ; i++)
            sum += arr[i] ;
            
        if(sum % 2)     //  odd sum cannot be divided into two halves
            return false ;

        return SubsetSumTarget(N, sum/2, arr) ;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends