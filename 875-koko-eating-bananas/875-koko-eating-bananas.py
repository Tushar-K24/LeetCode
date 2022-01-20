import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        def possible(x):
            hrs=0
            for i in piles: hrs+=math.ceil(i/x)
            if hrs>h: return False
            return True
        l,r = 0, piles[-1]
        while r-l!=1:
            m = (l+r)//2
            if possible(m): r=m
            else: l=m
            
        return r