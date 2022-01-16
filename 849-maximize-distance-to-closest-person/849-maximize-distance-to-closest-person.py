class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        prev, dist, n = -1, 0, len(seats)
        for i in range(n):
            if seats[i]:
                if prev==-1: dist=max(dist,(i-prev-1))
                else: dist=max(dist,(i-prev)//2)
                prev=i
        dist=max(dist,n-prev-1)
        return dist