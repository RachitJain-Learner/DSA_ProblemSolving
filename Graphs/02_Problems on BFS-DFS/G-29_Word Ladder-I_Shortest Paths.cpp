// G-29. Word Ladder - I | Shortest Paths

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q ;
        q.push({startWord, 1}) ;
        
        unordered_set<string> st(wordList.begin(), wordList.end()) ;
        st.erase(startWord) ;   //similar to marking visited, so not to visit/take again
        
        while(!q.empty()){
            string word = q.front().first ;
            int steps = q.front().second ;
            q.pop() ;
            
            if(word == targetWord){
                return steps ;
            }
            for(int i=0 ; i < word.size() ; i++){
                char original = word[i] ;
                for(char c='a' ; c<='z' ; c++){
                    word[i] = c ;
                    if(st.find(word) != st.end()){
                        st.erase(word) ;
                        q.push({word, steps+1}) ;
                    }
                }
                word[i] = original ;
            }
        } 
        return 0 ;
    }
};