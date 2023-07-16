// DP 31. Shortest Common Supersequence

#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{	
	// LCS Code
	int n = a.size(), m = b.size() ;
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=1 ; i<= n ; i++){
		for(int j=1; j<= m ; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1] ;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
			}
		}
	}
	// Printing
	string ans = "" ;

	int i = n, j= m ;
	while(i > 0 && j > 0){
		if(a[i-1] == b[j-1]){
			ans += a[i-1];
			i--, j-- ;
		}
		else if(dp[i-1][j] < dp[i][j-1]){
			ans += b[j-1];
			j-- ;
		}
		else{
			ans += a[i-1] ;
			i-- ;
		}
	}
	while(i > 0){
		ans += a[i-1] ;
		i-- ;
	}	
	while(j > 0){
		ans += b[j-1] ;
		j-- ;
	}
	reverse(ans.begin(), ans.end());
	return ans ;
} 