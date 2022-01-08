class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rows=len(grid)
        cols=len(grid[0])
        dp = [[[-1 for i in range(71)] for i in range(72)] for i in range(72)]
        def in_range(c):
            return c>=0 and c<cols
        
        def sol_dp(c1, c2, r):
            if r==rows:
                return 0
            if not in_range(c1) and not in_range(c2):
                return 0
            if dp[r][c1][c2]!=-1:
                return dp[r][c1][c2]
            if not in_range(c1):
                a1 = sol_dp(c1,c2-1,r+1)
                a2 = sol_dp(c1,c2,r+1)
                a3 = sol_dp(c1,c2+1,r+1)
                dp[r][c1][c2] = grid[r][c2] + max([a1,a2,a3])
                return dp[r][c1][c2]
            if not in_range(c2):
                a1 = sol_dp(c1-1,c2,r+1)
                a2 = sol_dp(c1,c2,r+1)
                a3 = sol_dp(c1+1,c2,r+1)
                dp[r][c1][c2] = grid[r][c1] + max([a1,a2,a3])
                return dp[r][c1][c2]
            if c1==c2:
                a1 = sol_dp(c1-1,c1,r+1)
                a2 = sol_dp(c1+1,c1,r+1)
                a3 = sol_dp(c1-1,c1+1,r+1)
                a4 = sol_dp(c1,c1,r+1)
                dp[r][c1][c2]=grid[r][c1] + max([a1,a2,a3,a4])
                return dp[r][c1][c2]
            a = 0
            for i in [-1,0,1]:
                for j in [-1,0,1]:
                    a = max(a,sol_dp(c1+i,c2+j,r+1))
            
            dp[r][c1][c2]=grid[r][c1] + grid[r][c2] + a
            return dp[r][c1][c2]
        return sol_dp(0,cols-1,0)