class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> f(60);
        for(int i:time){
            f[i%60]++;
        }
        int pairs=0;
        pairs += (f[0]*(f[0]-1))/2 + (f[30]*(f[30]-1))/2;
        for(int i=1;i<30;i++){
            pairs += f[i]*f[60-i];
        }
        return pairs;
    }
};