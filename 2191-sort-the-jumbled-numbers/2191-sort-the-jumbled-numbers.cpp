class Solution {
public:
    int map(vector<int> &mapping, int num){
        vector<int> digits;
        do{
            digits.push_back(num%10);
            num/=10;
        }while(num);
        reverse(digits.begin(),digits.end());
        int res=0;
        for(int i:digits){
            res*=10;
            res+=mapping[i];
        }
        return res;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mapped(nums.size());
        for(int i=0;i<nums.size();i++){
            mapped[i]={map(mapping,nums[i]),i};
        }    
        sort(mapped.begin(),mapped.end());
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++){
            result[i]=nums[mapped[i].second];
        }
        return result;
    }
};