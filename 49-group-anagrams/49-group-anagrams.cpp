class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(string s:strs){
            vector<int> f(26,0);
            for(char c:s) f[c-'a']++;
            mp[f].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};