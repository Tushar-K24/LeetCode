class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0: return 1
        x=1
        while x<=n: x<<=1
        return n^(x-1)