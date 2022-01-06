class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        passengers = [0]*1002
        for trip in trips:
            passengers[trip[1]]+=trip[0]
            passengers[trip[2]]-=trip[0]
        
        for i in range(1,1002):
            passengers[i]+=passengers[i-1]
        for i in passengers:
            if i>capacity:
                return False
        return True
            