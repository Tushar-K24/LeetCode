class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        vector<int> lengths;
        int l= last[s[0]-'a'];
        int cnt=1;
        for(int i=0;i<s.size();i++){
            l = max(l,last[s[i]-'a']);
            if(l==i){
                lengths.push_back(cnt);
                cnt=0;
            }
            cnt++;
        }
        return lengths;
    }
};