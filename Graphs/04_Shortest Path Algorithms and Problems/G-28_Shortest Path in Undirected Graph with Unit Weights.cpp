// G-28. Shortest Path in Undirected Graph with Unit Weights

class Solution {
private:
    void solveBFS(int src, vector<int>& dist, vector<int> adjLis[]){
        queue<int> q ;
        q.push(src) ;
        dist[src] = 0 ;
        
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            for(auto temp: adjLis[node]){
                if(dist[temp] > dist[node] + 1){   // store min distance
                    dist[temp] = dist[node] + 1 ;
                    q.push(temp) ;
                }
            }
        }
    }
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // make Adjacency List
        vector<int> adjLis[N] ;
        for(auto it: edges){
            adjLis[it[0]].push_back(it[1]) ;
            adjLis[it[1]].push_back(it[0]) ;
        }
        // no need of visited array
        vector<int> dist(N, INT_MAX) ;
        
        solveBFS(src, dist, adjLis) ;
        
        for(int i=0 ; i<N ; i++)
            if(dist[i] == INT_MAX)
                dist[i] = -1 ;
        
        return dist ;
    }
};