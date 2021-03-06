class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        st,n,curr = 0,len(gas),0
        for i in range(2*n):
            curr+=gas[i%n]-cost[i%n]
            if curr<0:
                st, curr = (i+1)%n, 0
            else:
                if i%n==(st-1)%n: 
                    return st
        return -1
        