class Solution:
    def partition(self, s: str) -> List[List[str]]:
        pal_check = lambda s: s==s[::-1]
        def sol_rec(s,n):
            if n==0:
                return [[]]
            res = []
            for i in range(n-1,-1,-1):
                if pal_check(s[i:n]):
                    rs = sol_rec(s,i)
                    for item in rs:
                        n_item = item[:]
                        n_item.append(s[i:n])
                        res.append(n_item)
            return res
        
        return sol_rec(s,len(s))