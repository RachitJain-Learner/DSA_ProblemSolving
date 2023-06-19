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

    bool solve(vector<int>& arr, int sum, int ind){
        if(ind == arr.size()){
            return 0;
        }
        
        if(sum == 0)
            return true ;
        
        int include = 0;
        if(sum >= arr[ind]){
            include = solve(arr, sum-arr[ind], ind+1);
        }
        
        int exclude = 0 + solve(arr, sum, ind+1);
        
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