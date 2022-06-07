#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-05 20:13:06
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        max_prophit = 0
        min_price = prices[0]

        for i in range(1, len(prices)):
            max_prophit = max(max_prophit, prices[i] - min_price)
            min_price = min(min_price, prices[i])

        return max_prophit

if __name__ == "__main__":
    module = Solution()
    print(module.maxProfit([7,6,4,3,1]))