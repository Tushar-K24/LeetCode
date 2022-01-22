class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        res = []
        res.append(False)
        for i in range(1,n+1):
            j,x = 1,True
            while j*j<=i:
                x&=res[i-j*j]
                j+=1
            res.append(not x)
        return res[n]