class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()&1) return {};
        vector<int> res;
        map<int,int> mp;
        for(int i:changed) mp[i]++;
        for(auto i:mp){
            if(mp[i.first]){
                if(i.first == 0){
                    if(i.second&1) return {};
                    for(int j=0;j<i.second/2; j++) res.push_back(0);
                }
                else{
                    if(mp.count(2*i.first) && mp[2*i.first]>=mp[i.first]){
                        for(int j=0;j<mp[i.first];j++) res.push_back(i.first);
                        mp[2*i.first] -= mp[i.first];
                    }
                    else{
                        return {};
                    }
                }
                mp[i.first] = 0;
            }
        }
        return res;
    }
};