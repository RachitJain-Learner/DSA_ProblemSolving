#include <bits/stdc++.h>

// Approach-1 
// TC - O(n*(m+m))      SC - O(m)

int largestRectangleArea(vector < int > & histo) {
	stack < int > st;
	int maxA = 0;
	int n = histo.size();
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
			int height = histo[st.top()];
			st.pop();
			int width;
			if (st.empty())
			width = i;
			else
			width = i - st.top() - 1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int> temp(m, 0);
	int maxArea = 0 ;
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(mat[i][j] == 1) temp[j]++ ;
			else	temp[j] = 0 ;
		}
		int area = largestRectangleArea(temp) ;
		maxArea = max(maxArea, area) ;
	}
	return maxArea ;
}

// Approach-2

#include <bits/stdc++.h>

vector<int> nextSmaller(vector<int>& heights, int n){
  vector<int> temp(n);
  stack<int> st ;
  st.push(-1) ;

  for(int i= n-1; i>= 0 ; i--){
    while(st.top() != -1 && heights[st.top()] >= heights[i]){
      st.pop() ;
    }
    temp[i] = st.top() ;
    st.push(i) ;
  }
  return temp ;
}

vector<int> prevSmaller(vector<int>& heights, int n){
  vector<int> temp(n);
  stack<int> st ;
  st.push(-1) ;

  for(int i= 0 ; i<n ; i++){
    while(st.top() != -1 && heights[st.top()] >= heights[i]){
      st.pop() ;
    }
    temp[i] = st.top() ;
    st.push(i) ;
  }
  return temp ;
}

int largestRectangleArea(vector < int > & heights) {
  int n = heights.size() ;

  vector<int> prev = prevSmaller(heights, n) ;
  vector<int> next = nextSmaller(heights, n) ;

  int maxArea = INT_MIN ;

  for(int i=0 ; i<n ; i++){
    if(next[i] == -1){
      next[i] = n ;
    }
    int breadth = next[i] - prev[i] - 1 ;
    maxArea = max(maxArea, heights[i] * breadth) ;
  }
  return maxArea ;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	
	vector<int> temp(m, 0);
	int maxArea = 0 ;
	
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			if(mat[i][j] == 1) temp[j]++ ;
			else	temp[j] = 0 ;
		}
		int area = largestRectangleArea(temp) ;
		maxArea = max(maxArea, area) ;
	}
	return maxArea ;
}