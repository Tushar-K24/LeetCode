class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        time_mod = {i:0 for i in range(60)}
        for t in time:
            time_mod[t%60]+=1
        cnt=0
        for t in time_mod:
            if t==0 or t==30: cnt+=time_mod[t]*(time_mod[t]-1)
            else: cnt+=time_mod[t]*time_mod[60-t]
        return cnt//2