# 121 Best Time to Buy and Sell Stock
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        tempMin = prices[0]
        maxDiff = 0
        
        for i in prices:
            if tempMin > i:
                tempMin = i
            if maxDiff < i - tempMin:
                maxDiff = i - tempMin
        
        return maxDiff