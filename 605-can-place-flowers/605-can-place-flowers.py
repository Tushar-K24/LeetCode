class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt=0
        for i in range(len(flowerbed)):
            c1,c2 = True,True
            if flowerbed[i]: continue
            if i-1>=0 and flowerbed[i-1]: c1=False
            if i+1<len(flowerbed) and flowerbed[i+1]: c2=False
            if c1 and c2:
                flowerbed[i]=1
                cnt+=1
        return cnt>=n