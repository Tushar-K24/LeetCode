class Node{
    Node *links[26];
    
public:    
    bool flag;
    Node(){
        for(int i=0;i<26;i++) links[i]=NULL;
        flag=false;
    }
    
    bool linkpresent(char c){
        return links[c-'a'];
    }
    
    Node* visitlink(char c){
        return links[c-'a'];
    }
    
    void addlink(char c){
        links[c-'a'] = new Node();
    }
};
class WordDictionary {
    Node *root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(char c:word){
            if(!node->linkpresent(c)){
                node->addlink(c);
            }
            node = node->visitlink(c);
        }
        node->flag = true;
    }
    bool search(string word, int idx, Node* node) {
        if(idx==word.size()) return node->flag;
        if(word[idx]!='.'){
            if(!node->linkpresent(word[idx])) return false;
            return search(word,idx+1,node->visitlink(word[idx]));
        }
        for(char i='a';i<='z';i++){
            if(node->linkpresent(i))
                if(search(word,idx+1,node->visitlink(i))) return true;
        }
        return false;
    }
    bool search(string word){
        Node *node = root;
        return search(word,0,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */