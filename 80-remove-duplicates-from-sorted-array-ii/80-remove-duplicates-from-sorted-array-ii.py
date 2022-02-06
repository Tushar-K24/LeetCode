class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        end = len(nums)
        for i in range(len(nums)):
            if i>=end: break
            ix = i
            while ix<end and nums[i]==nums[ix]:
                ix+=1
            cnt=ix-i
            if cnt>2:
                nums[i+2:end] = nums[end-1:i+1:-1]
                end-=cnt-2
        nums[:end]=sorted(nums[:end])
        return end
            