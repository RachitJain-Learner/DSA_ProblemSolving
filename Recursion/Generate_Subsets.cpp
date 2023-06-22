
// Subset-2
// Generate all unique subsets/subsequences from array containing duplicates

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp ){
        if(ind < 0){
            ans.push_back(temp) ;
            return ;
        }
        // include
        temp.push_back(nums[ind]) ;
        solve(ind-1, nums, ans, temp) ;
        temp.pop_back() ;
        
        // exclude all similar elements
        while(ind > 0 && nums[ind-1] == nums[ind])  ind-- ;
        solve(ind-1, nums, ans, temp) ;
    }
    
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp ;
        int n = nums.size() ;
        
        sort(nums.begin(), nums.end(), greater<int>()) ;
        solve(n-1, nums, ans, temp) ;
        
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";
    }
    return 0;
}
// } Driver Code Ends