class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0];
        int running_sum = 0;
        for(int i = 0; i<nums.size(); i++){
            running_sum += nums[i];
            curr_max = max(curr_max, running_sum);
            if(running_sum < 0)
                running_sum = 0;
        }
        return curr_max;
    }
};