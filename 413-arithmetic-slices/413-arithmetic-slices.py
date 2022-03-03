class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans,st,diff = 0,0,0
        for i in range(1,len(nums)):
            if nums[i]-nums[i-1]!=diff:
                diff = nums[i]-nums[i-1]
                cnt=i-st
                ans+=(cnt-1)*(cnt-2)//2
                st=i-1
        cnt=len(nums)-st
        ans+=(cnt-1)*(cnt-2)//2
        return ans