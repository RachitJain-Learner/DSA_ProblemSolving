DP 7. Ninja's Training

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Recursion
    int solve(int day, int lastTask, vector<vector<int>>& points){
        if(day == 0){
            int maxi = 0 ;
            for(int i= 0 ; i<= 2 ; i++){
                if(i != lastTask){
                    maxi = max(maxi, points[0][i]) ;
                }
            }
            return maxi ;
        }
        int maxPoints = 0 ;
        for(int i = 0; i < 3 ; i++){
            if(i != lastTask){
                int pts = points[day][i] + solve(day-1, i, points) ;
                maxPoints = max(maxPoints, pts);
            }
        }
        return maxPoints ;
    }
    
    // Memoization
    int solve(int day, int lastTask, vector<vector<int>>& points, vector<vector<int>>& dp){
        if(day == 0){
            int maxi = 0 ;
            for(int i= 0 ; i<= 2 ; i++){
                if(i != lastTask){
                    maxi = max(maxi, points[0][i]) ;
                }
            }
            return maxi ;
        }
        if(dp[day][lastTask] != -1){
            return dp[day][lastTask] ;
        }
        int maxPoints = 0 ;
        for(int i = 0; i < 3 ; i++){
            if(i != lastTask){
                int pts = points[day][i] + solve(day-1, i, points, dp) ;
                maxPoints = max(maxPoints, pts);
            }
        }
        return dp[day][lastTask] =maxPoints ;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1)) ;
        return solve(n-1, 3, points, dp) ;
    }
    
    // Tabulation
    int solve(vector<vector<int>>& points, int n){
        vector<vector<int>> dp(n, vector<int>(4, 0)) ;
        
        for(int t = 0 ; t <= 3 ; t++){
            int maxi = 0 ;
            for(int i= 0 ; i<= 2 ; i++){
                if(i != t){
                    maxi = max(maxi, points[0][i]) ;
                }
            }
            dp[0][t] = maxi ;
        }
        for(int day = 1 ; day < n ; day++){
            for(int lastTask=0 ; lastTask <= 3 ; lastTask++){
                int maxPoints = 0 ;
                for(int i = 0; i < 3 ; i++){
                    if(i != lastTask){
                        int pts = points[day][i] + dp[day-1][i] ;
                        maxPoints = max(maxPoints, pts);
                    }
                }
                dp[day][lastTask] = maxPoints ;
            }
        }
        return dp[n-1][3] ;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        return solve(points, n) ;
    } 
    
    // Space Optimisation
    int solve(vector<vector<int>>& points, int n){
        vector<int> prev(4, 0), curr(4, 0) ;
        
        for(int t = 0 ; t <= 3 ; t++){
            int maxi = 0 ;
            for(int i= 0 ; i<= 2 ; i++){
                if(i != t){
                    maxi = max(maxi, points[0][i]) ;
                }
            }
            prev[t] = maxi ;
        }
        for(int day = 1 ; day < n ; day++){
            for(int lastTask=0 ; lastTask <= 3 ; lastTask++){
                int maxPoints = 0 ;
                for(int i = 0; i < 3 ; i++){
                    if(i != lastTask){
                        int pts = points[day][i] + prev[i] ;
                        maxPoints = max(maxPoints, pts);
                    }
                }
                curr[lastTask] = maxPoints ;
            }
            prev = curr ;
        }
        return prev[3] ;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        return solve(points, n) ;
    }  
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }
        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends