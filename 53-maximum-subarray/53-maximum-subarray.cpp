class Solution {
public:
    int helper(vector<vector<int>> &dp,vector<int> &nums, int n, bool flag) {
        if(n == 0) {
            if(!flag) return INT_MIN;
            return 0;
        }
        if(dp[n][flag]!=-1e9-7) return dp[n][flag];
        if(flag) return dp[n][flag]=max(0,nums[n-1]+helper(dp,nums,n-1,true));
        return dp[n][flag]=max(nums[n - 1] + helper(dp,nums, n - 1, true), helper(dp,nums, n - 1,false));
    }
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(2,-1e9-7));
        return helper(dp,nums, nums.size(),false);
    }
};