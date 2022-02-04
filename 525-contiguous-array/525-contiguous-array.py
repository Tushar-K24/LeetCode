class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        pref = []
        for i in nums:
            if len(pref)==0: pref.append(i)
            else: pref.append(i+pref[-1])
        for idx in range(len(pref)):
            pref[idx]<<=1
            pref[idx]-=idx
            
        first, res = {}, 0
        first[1] = -1
        for idx,i in enumerate(pref):
            if i not in first.keys():
                first[i]=idx
            res = max(res,idx - first[i])
        return res
    