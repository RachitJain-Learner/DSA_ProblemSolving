// Problems on BFS-DFS/G-09_Flood Fill Algorithm.cpp

// Method 1 - Passing both 2D grids
class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>>& copy, int initColor, int newColor, int drow[], int dcol[]){
        copy[sr][sc] = newColor ;
        
        int m = image.size() ;
        int n = image[0].size() ;
        
        for(int i= 0 ; i < 4 ; i++){
            int nrow = sr + drow[i] ;
            int ncol = sc + dcol[i] ;
            if(nrow >= 0 && nrow < m  && ncol >= 0 && ncol < n && 
            image[nrow][ncol] == initColor && copy[nrow][ncol] != newColor)
            {
                dfs(nrow, ncol, image, copy, initColor, newColor, drow, dcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int start = image[sr][sc] ;
        vector<vector<int>>copy = image ;
        
        int drow[] = {-1, 0, +1, 0} ;
        int dcol[] = {0, +1, 0, -1} ;
        
        dfs(sr, sc, image, copy, start, newColor, drow, dcol);
        return copy ;
    }
};

// Method 2 - Passing single 2D grids
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& copy, int newColor, int initColor, int drow[], int dcol[] ){
        copy[row][col] = newColor ;
        
        int n = copy.size() ;
        int m = copy[0].size() ;
        
        for(int i=0 ; i<4 ; i++){
            int nrow = row + drow[i] ;
            int ncol = col + dcol[i] ;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && copy[nrow][ncol] == initColor && initColor != newColor)
            {
                dfs(nrow, ncol, copy, newColor, initColor, drow, dcol) ;
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        vector<vector<int>> copy = image ;
        int initColor = copy[sr][sc] ;
        
        int drow[] = {-1, 0, 1, 0} ;
        int dcol[] = {0, 1, 0, -1} ;
        
        dfs(sr, sc, copy, newColor, initColor, drow, dcol) ;
        return copy ;
    }
};
