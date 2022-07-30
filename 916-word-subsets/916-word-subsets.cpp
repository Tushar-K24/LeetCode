class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int universal_f[26] = {0};
        for(string word:words2){
            int f[26] = {0};
            for(char c:word){
                f[c-'a']++;
            }
            for(int i=0;i<26;i++) universal_f[i] = max(universal_f[i], f[i]);
        }
        vector<string> ans;
        for(string word:words1){
            int f[26] = {0};
            for(char c:word){
                f[c-'a']++;
            }
            bool universal = true;
            for(int i=0;i<26;i++) if(f[i]<universal_f[i]) universal = false;
            if(universal) ans.push_back(word);
        }
        return ans;
    }
};