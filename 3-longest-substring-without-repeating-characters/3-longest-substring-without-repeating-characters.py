class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        occurrence = {}
        ans,start = 0,0
        for idx, i in enumerate(s):
            if i not in occurrence.keys(): occurrence[i]=idx
            elif occurrence[i]>=start:
                ans=max(ans,idx-start)
                start=occurrence[i]+1
                occurrence[i]=idx
            else: occurrence[i]=idx
        ans=max(ans,len(s)-start)
        return ans