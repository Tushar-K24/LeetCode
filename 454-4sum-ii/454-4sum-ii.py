class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        
        cnt, f12, f34 = 0, {}, {}
        for i in nums1:
            for j in nums2:
                s = i+j
                if s not in f12.keys():
                    f12[s]=0
                f12[s]+=1
        
        for i in nums3:
            for j in nums4:
                s = i+j
                if s not in f34.keys():
                    f34[s]=0
                f34[s]+=1
        for s in f12.keys():
            if -s in f34.keys():
                cnt+= f12[s]*f34[-s]
        return cnt