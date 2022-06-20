class Solution {
public:
    bool inside(string &s1, string &s2){
        //check if s1 fits inside s2
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;i++){
            if(s1[n-i-1]!=s2[m-i-1]) 
                return false;
        }
        return true;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int len=0;
        sort(words.begin(), words.end(), [&](string &s1, string &s2){
            return s1.size()<s2.size();
        });
        for(int i=0;i<words.size();i++){
            bool ok=false;
            for(int j=i+1;j<words.size();j++){
                if(inside(words[i], words[j])){
                    ok=true;
                    break;
                }
            }
            if(!ok){
                len+=words[i].size()+1;
            }
        }    
        return len;
    }
};