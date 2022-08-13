class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n), ans(n);
        for(int i=0;i<n;i++){
            pref[i] = suff[i] = nums[i];
        }
        for(int i=1;i<n;i++) pref[i]*=pref[i-1];
        for(int i=n-2;i>=0;i--) suff[i]*=suff[i+1];
        for(int i=0;i<n;i++){
            int p1 = 1, p2 = 1;
            if(i) p1 = pref[i-1];
            if(i+1<n) p2 = suff[i+1];
            ans[i] = p1*p2;
        }
        return ans;
    }
};