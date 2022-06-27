class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        for(int i=0;i<n;i++) pref[i]=nums[i];
        for(int i=1;i<n;i++) pref[i]+=pref[i-1];
        return pref;
    }
};