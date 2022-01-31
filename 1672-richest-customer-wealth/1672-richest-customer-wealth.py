import numpy as np
class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(np.sum(accounts,axis=1))