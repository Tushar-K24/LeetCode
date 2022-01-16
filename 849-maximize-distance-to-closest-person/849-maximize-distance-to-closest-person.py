class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        pos=[]
        for idx,i in enumerate(seats):
            if i: pos.append(idx)
        dist=max(pos[0],len(seats)-pos[-1]-1)
        for i in range(1,len(pos)):
            dist=max(dist,(pos[i]-pos[i-1])//2)
        return dist