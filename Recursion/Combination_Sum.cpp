// Combination Sum I

class Solution {
public:
    void helper(int ind, int sum, vector<int> &A, vector<int> &temp, vector<vector<int>> &ans){
        
        if(sum == 0){   //base case
            ans.push_back(temp) ;
            return ;
        }
        if(sum < 0 || ind == A.size()) 
            return ;
        
        temp.push_back(A[ind]) ;
        helper(ind, sum-A[ind], A, temp, ans) ; //take
        temp.pop_back() ;
        
        helper(ind+1, sum, A, temp, ans) ; //not take
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> temp ;
        
        sort(candidates.begin(), candidates.end()) ;
        
        helper(0, target, candidates, temp, ans) ;
        return ans;
    }
};


// Combination Sum II

class Solution {
    void solve(int ind, vector<int>& a, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        if(target < 0 || ind == a.size())
            return ;

        temp.push_back(a[ind]) ;
        solve(ind+1, a, target-a[ind], temp, ans) ;
        temp.pop_back() ;

        // Nottake all same elements
        while(ind+1 < a.size() && a[ind+1] == a[ind]) ind++ ;

        solve(ind+1, a, target, temp, ans) ;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        
        sort(candidates.begin(), candidates.end()) ;
        solve(0, candidates, target, temp, ans) ;
        return ans ;
    }
};