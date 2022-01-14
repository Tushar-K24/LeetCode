class Solution:
    def myAtoi(self, s: str) -> int:
        sign=1
        s=s.strip()
        if s=="":
            return 0
        if s[0]=='-':
            s=s[1:]
            sign*=-1
        elif s[0]=='+':
            s=s[1:]
        mx = 2**31
        mn=-mx
        mx-=1
        num=0
        for i in s:
            if not i.isnumeric():
                break
            num=num*10 + int(i)
            if sign*num<=mn:
                num=abs(mn)
                break
            if sign*num>=mx:
                num=abs(mx)
                break
        return sign*num