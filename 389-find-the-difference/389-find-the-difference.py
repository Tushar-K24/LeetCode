class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        letters = 'abcdefghijklmnopqrstuvwxyz'
        fs = {}
        for i in s:
            if i not in fs.keys():
                fs[i]=0
            fs[i]+=1
        for i in t:
            if i not in fs.keys():
                return i
            fs[i]-=1
            if fs[i]==-1:
                return i
            