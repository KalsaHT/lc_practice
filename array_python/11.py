# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-29 10:14:08
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        start = 0
        end = len(height) - 1

        max_contrainer = 0

        while start < end:
            new_container = min(height[start], height[end]) * (end - start)
            max_contrainer = max_contrainer if  < max_contrainer else new_container

            if height[start] < height[end]:
                start += 1
            else:
                end -= 1
        return max_contrainer

if __name__ == "__main__":
    solution = Solution()
    