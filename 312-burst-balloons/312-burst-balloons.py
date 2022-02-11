class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp = [[-1 for _ in nums] for _ in nums]
        def sol_dp(i,j):
            if i>j: return 0
            if dp[i][j]!=-1: return dp[i][j]
            #print('for {} and {}'.format(i,j))
            l = 1 if i-1<0 else nums[i-1]
            r = 1 if j+1>=len(nums) else nums[j+1]    
            for k in range(i,j+1):
                #print('for k: {}'.format(k))
                temp = nums[k]*l*r + sol_dp(i,k-1) + sol_dp(k+1,j)
                #print('temp: {}'.format(temp))
                dp[i][j] = max(dp[i][j],temp)
            return dp[i][j]
        return sol_dp(0,len(nums)-1)