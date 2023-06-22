// Return sum of all subsets

// Subset Sum - 1

#include<bits/stdc++.h>
class Solution{
public:
    void solve(vector<int> &arr, int N, int ind, int sum, vector<int> &ans){
        if(ind == N){
            ans.push_back(sum) ;
            return ;
        }
        solve(arr, N, ind+1, sum + arr[ind], ans);  //take
        
        solve(arr, N, ind+1, sum, ans); // not take
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {   
        vector<int> ans;
        solve(arr, N, 0, 0, ans);
        
        return ans ;
    }
};