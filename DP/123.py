#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-06 18:55:24
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<=1:
            return 0

        b1 = -prices[0]
        b2 = 0
        b3 = -prices[0]
        b4 = 0

        for i in range(1, len(prices)):
            b1 = max(b1, -prices[i])
            b2 = max(b2, b1 + prices[i])
            b3 = max(b3, b2 - prices[i])
            b4 = max(b4, b3 + prices[i])

        return b4

if __name__ == "__main__":
    module = Solution()
    print(module.maxProfit([3,3,5,0,0,3,1,4]))