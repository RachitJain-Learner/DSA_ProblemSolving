//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

// Not possible using for loop since we have to only take array elements, no infinite supply => 2D DP
// If infinite supply then use "for loop" to take repetitive cases

class Solution{  
public:

    

    // Memoization Method-1 : from 0 to n
    bool solveMemo(vector<int>& arr, int sum, int ind, vector<vector<int>>& dp){
        if(sum == 0)
            return true ;
            
        if(ind == arr.size())
            return 0;

        if(dp[ind][sum] != -1){
            return dp[ind][sum];
        }
        
        bool include = 0;
        if(sum >= arr[ind]){
            include = solveMemo(arr, sum-arr[ind], ind+1, dp);
        }
        bool exclude = solveMemo(arr, sum, ind+1, dp);
        
        return dp[ind][sum] = include || exclude ;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<int>>dp(n, vector<int>(sum+1, -1)) ;
        return solveMemo(arr, sum, 0, dp);
    }
    
    // Memoization Method-2 : from n-1 to 0
    bool solveMemo(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0)
        return true;
    
        if(ind == 0)
            return arr[0] == target;
        
        if(dp[ind][target]!=-1)
            return dp[ind][target];
            
        bool notTaken = solveMemo(ind-1,target,arr,dp);
        
        bool taken = false;
        if(arr[ind]<=target)
            taken = solveMemo(ind-1,target-arr[ind],arr,dp);
            
        return dp[ind][target]= notTaken||taken;
    }
    bool isSubsetSum(vector<int>arr, int sum){

        vector<vector<int>>dp(n, vector<int>(sum+1, -1)) ;
        return solveMemo(n-1, sum ,arr,dp);
    }

    // Recursion
    bool solve(vector<int>& arr, int sum, int ind){
        if(sum == 0)
            return true ;
        
        if(ind == arr.size())   
            return 0;
        
        int include = 0;
        if(sum >= arr[ind]){
            include = solve(arr, sum-arr[ind], ind+1);
        }
        int exclude = solve(arr, sum, ind+1);
        
        return include || exclude ;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        return solve(arr, sum, 0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends