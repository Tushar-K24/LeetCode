class Solution {
    unordered_map<char,int> mp; 
public:
    void insert(char c){
        mp[c]++;
        if(mp[c]==0) mp.erase(c);
    }
    
    void remove(char c){
        mp[c]--;
        if(mp[c]==0) mp.erase(c);
    }
    
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        for(char c:p) insert(c);
        for(int i=0;i<m;i++) remove(s[i]);
        vector<int> res;
        for(int i=0;i<n-m;i++){
            if(mp.size()==0){
                res.push_back(i);
            }
            insert(s[i]);
            remove(s[i+m]);
        }
        if(mp.size()==0){
            res.push_back(n-m);
        }
        return res;
    }
};