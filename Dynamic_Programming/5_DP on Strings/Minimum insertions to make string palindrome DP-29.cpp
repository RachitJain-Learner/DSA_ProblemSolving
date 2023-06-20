class Solution {
public:
    int LCS(string &a, string &b) {
        int m = a.length() ;
        int n = b.length() ;

        vector<int> prev(n+1, 0) ;
        vector<int> curr(n+1, 0) ;

        for(int i=1 ; i<=m ; i++){
            for(int j=1 ; j<=n ; j++){
                int ans = 0 ;
                if(a[i-1] == b[j-1])
                    ans = 1 + prev[j-1] ;
                else{
                    int ans1 = curr[j-1] ; 
                    int ans2 = prev[j] ;

                    ans = max(ans1, ans2) ;
                }
                curr[j] = ans ;
            }
            prev = curr ;
        }
        return prev[n] ;   
    }
    
    int minInsertions(string s) {
        int n = s.size();
        
        string r = s;
        reverse(r.begin(), r.end());
        
        return n - LCS(s, r);
    }
};