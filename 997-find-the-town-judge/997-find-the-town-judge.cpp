class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_map<int,int>> mp(n+1);
        for(auto i:trust){
            mp[i[0]][i[1]]++;
        }
        int judge=-1;
        for(int i=1;i<=n;i++){
            if(mp[i].size()==0){
                judge=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=judge){
                if(mp[i][judge]==0) return -1;
            }
        }
        return judge;
    }
};