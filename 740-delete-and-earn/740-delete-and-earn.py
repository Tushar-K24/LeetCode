class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        f = [0 for i in range(int(1e4+1))]
        for num in nums:
            f[num]+=1
        dp = [0 for i in range(int(1e4+1))]
        for i in range(1,int(1e4+1)):
            if i==1:
                dp[i]=i*f[i]
            dp[i]=max(dp[i-1],dp[i-2]+i*f[i])
        return dp[-1]