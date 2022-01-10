class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a,b = a[::-1],b[::-1]
        n = max(len(a), len(b))
        a+="0"*(n-len(a))
        b+="0"*(n-len(b))
        carry=0
        ans=""
        for i in range(n):
            x,y = int(a[i]), int(b[i])
            s = x+y+carry
            carry=s//2
            ans+=str(s%2)
        if carry:
            ans+=str(carry)
        ans=ans[::-1]
        return ans