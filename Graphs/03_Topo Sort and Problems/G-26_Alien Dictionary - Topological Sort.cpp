// G-26. Alien Dictionary - Topological Sort
// Approach - Main work is to create adjacency List & Then TopoSort - BFS

class Solution{
    vector<int> TopoSort(int V, vector<int> adjLis[]){
        int indegree[V] = {0} ;
        for(int i=0 ; i<V ; i++){
            for(auto it: adjLis[i])
                indegree[it]++ ;
        }
        
        queue<int> q ;
        for(int i=0 ; i<V ; i++){
            if(indegree[i] == 0)
                q.push(i) ;
        }
        vector<int> temp ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            
            temp.push_back(node) ;
            
            for(auto adj: adjLis[node]){
                indegree[adj]-- ;
                if(indegree[adj] == 0)
                    q.push(adj) ;
            }
        }
        return temp ;
    }
public:
    string findOrder(string dict[], int N, int K) {
        // Main work is to create adjacency List
        vector<int> adjLis[K] ;
        for(int i=0 ; i< N-1 ; i++){
            string s1 = dict[i] ;
            string s2 = dict[i+1] ;
            
            int len = min(s1.size(), s2.size()) ;
            // int ptr = 0 ;
            // while(s1[ptr] == s2[ptr] && ptr < len)   ptr++ ;
            for(int ptr=0 ; ptr<len ; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adjLis[s1[ptr] - 'a'].push_back(s2[ptr] - 'a') ;
                    break ;
                }
            }
        }
        //  Get TopoSort order
        vector<int> temp = TopoSort(K, adjLis) ; 
        
        string ans = "" ;
        for(auto it: temp){
            ans += it + 'a' ;
        }
        return ans ;
    }
};