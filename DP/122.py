#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-05 20:36:00
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) <=1:
            return 0

        total = 0
        buy_in = prices[0]

        for i, n in enumerate(prices[1:]):
            total += max(0, n - buy_in)
            buy_in = n

        return total
if __name__ == "__main__":
    module = Solution()
    print(module.maxProfit([5, 7, 6]))