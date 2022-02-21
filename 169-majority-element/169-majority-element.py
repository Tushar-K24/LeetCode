class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        f = {}
        for num in nums:
            if num not in f.keys():
                f[num]=0
            f[num]+=1
            if f[num]>len(nums)//2:
                return num
        return nums[0]