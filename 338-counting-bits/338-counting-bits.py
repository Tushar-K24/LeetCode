class Solution:
    def countBits(self, n: int) -> List[int]:
        bitcount=[0 for i in range(n+1)]
        for i in range(1,n+1):
            bitcount[i]=bitcount[i-1]
            for j in range(18):
                x = (1<<j)-1
                if x&(i-1) != x:
                    bitcount[i] -= j-1
                    bitcount[i] += 1
                    break
        return bitcount