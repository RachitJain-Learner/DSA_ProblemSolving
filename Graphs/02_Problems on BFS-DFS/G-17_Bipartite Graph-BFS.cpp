// G-17. Bipartite Graph | BFS |

// Method-1 - Better 
class Solution {
private: 
    bool checkBipartite(int node, vector<int>& color, vector<int>adj[]){
        queue<int> q;
	    q.push(node) ;
	    color[node] = 1 ;   
	    // second parameter not required since we are marking colors in visited color array
	    while(!q.empty()){
	        int node = q.front() ;
	        q.pop() ;
	        
	        for(auto neighNode: adj[node]){
	            //if neighbour node not colored
	            if(color[neighNode] == -1){
	                q.push(neighNode) ;
	                color[neighNode] = !color[node] ;
	            }
	            //if neighbour node colored with same color
	            else if(color[neighNode] == color[node]){
	                return false ;
	            }
	        }
	    }
	    return true ;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1) ;
	    
	    for(int i=0 ; i<V ; i++){
	        if(color[i] == -1){
	            if(checkBipartite(i, color, adj) == false)
	                return false ;
	        }
	    }
	    return true ;
	}
};

// Method-2 - Using queue with (node, color)
// It will be used when marking 0/1 in visited array
class Solution {
private: 
    bool checkBipartite(int node, vector<int>& color, vector<int>adj[]){
        queue<pair<int, int>> q;
	    q.push({node, 1}) ;
	    color[node] = 1 ;   
	    // second parameter not required since we are marking colors in visited color array
	    while(!q.empty()){
	        int node = q.front().first ;
	        int nodeColor = q.front().second ;
	        q.pop() ;
	        
	        for(auto neighNode: adj[node]){
	            //if neighbour node not colored
	            if(color[neighNode] == -1){
	                q.push({neighNode, !nodeColor}) ;
	                color[neighNode] = !nodeColor ;
	            }
	            //if neighbour node colored with same color
	            else if(color[neighNode] == nodeColor){
	                return false ;
	            }
	        }
	    }
	    return true ;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1) ;
	    
	    for(int i=0 ; i<V ; i++){
	        if(color[i] == -1){
	            if(checkBipartite(i, color, adj) == false)
	                return false ;
	        }
	    }
	    return true ;
	}
};