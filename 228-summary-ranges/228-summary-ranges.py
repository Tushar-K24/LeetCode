class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        st,res=0,[]
        if not len(nums):
            return []
        for i in range(1,len(nums)):
            if nums[i]-nums[i-1]>1:
                if i-1==st:
                    res.append(str(nums[st]))
                else:
                    res.append(str(nums[st])+"->"+str(nums[i-1]))
                st=i
        if len(nums)==st+1:
            res.append(str(nums[st]))
        else:
            res.append(str(nums[st])+"->"+str(nums[-1]))
        return res