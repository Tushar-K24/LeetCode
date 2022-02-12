class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> encoded_words;
        int n=wordList.size();
        for(int i=0;i<n;i++){
            encoded_words[wordList[i]]=i;
        }
        if(encoded_words.find(endWord)==encoded_words.end()) return 0;
        if(encoded_words.find(beginWord)==encoded_words.end()){
            encoded_words[beginWord]=n;
        }
        vector<int> adj[encoded_words.size()];
        for(auto it:encoded_words){
            string new_word = it.first;
            for(int i=0;i<new_word.size();i++){
                char curr = new_word[i];
                for(char c='a';c<='z';c++){
                    if(c==curr) continue;
                    new_word[i]=c;
                    if(encoded_words.find(new_word)!=encoded_words.end()){
                        adj[it.second].push_back(encoded_words[new_word]);
                    }
                }
                new_word[i]=curr;
            }
        }
        queue<int> q;
        vector<int> visited(encoded_words.size());
        visited[encoded_words[beginWord]]=1;
        q.push(encoded_words[beginWord]);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i:adj[x]){
                if(!visited[i]){
                    visited[i] = visited[x]+1;
                    q.push(i);
                }
            }
        }
        return visited[encoded_words[endWord]];
    }
};