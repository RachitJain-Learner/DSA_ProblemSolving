// G-11. Detect a Cycle in an Undirected Graph using BFS

#include <queue>
bool usingBFS(vector<int> adjLs[], int start, int vis[]){
    queue<pair<int, int>> q ;
    q.push({start, -1});
    vis[start] = 1 ;

    while(!q.empty()){
        int node = q.front().first ;
        int parent = q.front().second ;
        q.pop();

        for(auto temp: adjLs[node]){
            if(!vis[temp]){
                q.push({temp, node}) ;
                vis[temp] = 1;
            }
            // temp is visited by another side/node
            else if(parent != temp){  //node visited while traversing
                return true ;
            }
        }
    }
    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{   
    // Creation of Adj List
    vector<int> adjLs[n+1] ;
    for(int i=0; i<m ; i++){
        adjLs[edges[i][0]].push_back(edges[i][1]) ; 
        adjLs[edges[i][1]].push_back(edges[i][0]) ; 
    }

    int vis[n+1] = {0} ;
    // For Connected Components
    for(int i=1 ; i <= n ; i++){
        if(!vis[i]){    //  you are visited because linear connection
            if(usingBFS(adjLs, i, vis) == true){
                return "Yes" ;
            }
        }
    }
    return "No" ;
}