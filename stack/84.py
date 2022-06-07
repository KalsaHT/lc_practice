#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-01 09:48:53
'''
import enum
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

# 超时
class Solution1(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """

        if len(heights) == 0:
            return 0

        if len(heights) == 1:
            return heights[0]
        
        shortest = float("inf")
        shortest_index = -1

        for i, n in enumerate(heights):
            if n < shortest:
                shortest = n
                shortest_index = i

        
        volumn = shortest * len(heights)
        # print(shortest, len(heights), heights)

        return max(self.largestRectangleArea(heights[:shortest_index]), self.largestRectangleArea(heights[shortest_index+1:]), volumn)


class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        if len(heights) == 0:
            return 0

        if len(heights) == 1:
            return heights[0]

        res = 0
        heights = [0] + heights + [0]
        stack = [0]

        for i, h in enumerate(heights):
            if i == 0:
                continue

            while (h < heights[stack[-1]]):
                cur_h = heights[stack[-1]]
                stack.pop()
                res = max(res, (i-stack[-1]-1)*cur_h)
                # print(res, cur_h, stack)

            stack.append(i)

        return res

if __name__ == "__main__":
    module = Solution()
    print(module.largestRectangleArea([2,1,5,6,2,3]))
