class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                int mn_idx = i+1;
                for(int j = i+1; j<nums.size(); j++){
                    if((nums[j]>nums[i]) && (nums[j]<nums[mn_idx])){
                        mn_idx = j;
                    }
                }
                swap(nums[i], nums[mn_idx]);
                break;
            }
        }
        sort(nums.begin()+i+1, nums.end());
    }
};