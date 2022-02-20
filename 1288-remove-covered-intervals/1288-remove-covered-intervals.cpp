class Solution {

    public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<bool> marked(n,true);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(marked[j]){
                    if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1])
                        marked[j]=false;
                }
            }
        }
        int cnt=0;
        for(bool i:marked) cnt+=i;
        return cnt;
    }
};