class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int diff=nums[1]-nums[0],st=0,ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]!=diff){
                diff=nums[i]-nums[i-1];
                int cnt=i-st;
                st=i-1;
                ans+=((cnt-1)*(cnt-2))/2;
            }
        }
        int cnt=n-st;
        ans+=((cnt-1)*(cnt-2))/2;
        return ans;
    }
};