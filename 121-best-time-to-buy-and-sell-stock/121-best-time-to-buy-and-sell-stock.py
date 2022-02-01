class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mn, profit = prices[0],0
        for price in prices:
            if price<mn:
                mn=price
            else:
                profit = max(profit,price-mn)
        return profit