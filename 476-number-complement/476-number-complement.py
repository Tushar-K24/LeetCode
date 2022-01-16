class Solution:
    def findComplement(self, num: int) -> int:
        if num==0: return 1
        x=1
        while x<=num: x<<=1
        return num^(x-1)