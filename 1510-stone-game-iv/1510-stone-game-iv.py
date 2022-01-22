class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        res = []
        res.append(False)
        for i in range(1,n+1):
            j,x = 1,False
            while j*j<=i:
                x|=not res[i-j*j]
                j+=1
            res.append(x)
        return res[n]