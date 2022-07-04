#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-13 21:22:43
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        days = len(prices)
        buy = [[0]*(k+1) for _ in range(days)]
        sell = [[0]*(k+1) for _ in range(days)]

        
        buy[0][0] = -prices[0]
        for i in range(1, k+1):
            buy[0][i] = -float("inf")
            sell[0][i] = -float("inf")

        for i in range(1, days):
            buy[i][0] = max(buy[i-1][0], sell[i-1][0]-prices[i])

            for j in range(1, k+1):
                buy[i][j] = max(buy[i-1][j], sell[i-1][j] - prices[i])
                sell[i][j] = max(sell[i-1][j], buy[i-1][j-1] + prices[i])

        
        return max(sell[-1])

if __name__ == "__main__":
    module = Solution()
    print(module.maxProfit(2, [2,4,1]))