class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        dic, cnt = {},0
        for num in nums:
            if num not in dic.keys():
                dic[num]=0
            dic[num]+=1
        for num in dic.keys():
            if k==0:
                if dic[num]>1:
                    cnt+=1
            else:
                if num-k in dic.keys():
                    cnt+=1
        return cnt