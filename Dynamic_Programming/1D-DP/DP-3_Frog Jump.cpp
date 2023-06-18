//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int>& height, int ind, vector<int> &dp){
        if(ind == 0)
            return 0;
        if(ind == 1)
            return abs(height[1] - height[0]);
        
        if(dp[ind] != -1){
            return dp[ind] ;
        }
        
        int oneStep = abs(height[ind] - height[ind-1]) + solve(height, ind-1, dp) ;
        int twoStep = abs(height[ind] - height[ind-2]) + solve(height, ind-2, dp) ;
        
        return dp[ind] = min(oneStep, twoStep) ;
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        
        vector<int> dp(n, -1);
        return solve(height, n-1, dp) ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends