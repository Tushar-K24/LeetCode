class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        def next_smaller2right():
            nxt_smol2right = []
            stack = []
            for i in range(len(num)-1,-1,-1):
                while len(stack) and num[stack[-1]]>=num[i]:
                    stack.pop()
                if len(stack)==0:
                    nxt_smol2right.append(len(num))
                else:
                    nxt_smol2right.append(stack[-1])
                stack.append(i)
            return nxt_smol2right[::-1]
        
        nxt_smol2right = next_smaller2right()
        res = ""
        ix=0
        while ix<len(num):
            if nxt_smol2right[ix]-ix>k:
                res+=num[ix]
                ix+=1
            else:
                k-=nxt_smol2right[ix]-ix
                ix=nxt_smol2right[ix]
        res = res.lstrip('0')
        if len(res)==0:
            res='0'
        return res