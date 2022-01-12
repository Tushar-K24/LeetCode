class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums)==0:
            return [-1,-1]
        def first(nums, target):
            l,r=-1,len(nums)
            while r-l!=1:
                m=(l+r)//2
                if nums[m]<target:
                    l=m
                else:
                    r=m
            if r==len(nums) or nums[r]!=target:
                return -1
            return r
        
        def last(nums, target):
            l,r=-1,len(nums)
            while r-l!=1:
                m=(l+r)//2
                if nums[m]<=target:
                    l=m
                else:
                    r=m
            if nums[l]==target:
                return l
            return -1
        return [first(nums,target),last(nums,target)]
