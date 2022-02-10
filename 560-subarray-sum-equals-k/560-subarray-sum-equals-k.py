class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        nums_dic, cnt, pref = {},0,0
        nums_dic[0]=1
        for num in nums:
            pref+=num
            if pref not in nums_dic.keys():
                nums_dic[pref]=0
            if pref-k in nums_dic.keys():
                cnt+=nums_dic[pref-k]
            nums_dic[pref]+=1
            
        return cnt
            