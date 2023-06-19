#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){

    int maxProfit = INT_MIN ;
    int minPrice = prices[0] ;

    for(int i=1; i<prices.size(); i++){
        
        minPrice = min(minPrice, prices[i]) ;
        maxProfit = max(maxProfit, prices[i]-minPrice);
    }
    return maxProfit ;
}