Partition Set Into 2 Subsets With Min Absolute Sum Diff (DP- 16)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    // Tabulation
    int solveAns(int arr[], int n, int sum)  { 
        int amount = sum/2 ;    // By observation, runnig till sum/2
        
        // Step-2 : Build 2D Matrix
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0)) ;
        
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
        
        // Step-3 --> Find min Difference
        int minDiff = INT_MAX ;
        
        for(int s=0 ; s <= amount ; s++){
            if(dp[n-1][s] == 1){    // checking whether a sum is present in 2D or not
                
                int tempDiff = abs((sum - s) - s) ;
                minDiff = min(minDiff, tempDiff) ;
            }
        }
        return minDiff ;
    }
	int minDifference(int arr[], int n)  { 
	    
	   // Step-1 --> Find Sum
	    int sum = 0 ;
	    for(int i=0 ; i<n ; i++)
	        sum += arr[i] ;
	    
	    return solveAns(arr, n, sum) ;
	} 
	
    // Space Optimisation
	int minDifference(int arr[], int n)  { 
	    
	   // Step-1 --> Find Sum
	    int sum = 0 ;
	    for(int i=0 ; i<n ; i++)
	        sum += arr[i] ;
	    
	    int amount = sum/2 ;    // By observation, runnig till sum/2
        
        // Step-2 : Build 2D Matrix
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0) ; 
        
        curr[0] = 1 ;
        prev[0] = 1 ;
        
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
        
        // Step-3 --> Find min Difference
        int minDiff = INT_MAX ;
        
        for(int s=0 ; s <= amount ; s++){
            if(prev[s] == 1){    // checking whether a sum is present in 2D or not
                
                int tempDiff = abs((sum - s) - s) ;
                minDiff = min(minDiff, tempDiff) ;
            }
        }
        return minDiff ;
	}
};


//{ Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends