# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-05 17:58:55
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        N = len(nums)
        cur, prev = 0, 0
        res = float("-inf")
        for i in range(N):
            cur = nums[i] + (prev if prev > 0 else 0)
            prev = cur
            print(cur)
            res = max(res, cur)
            print(res)
        return res


if __name__ == "__main__":
    solu = Solution()
    examples = [[-2,1,-3,4,-1,2,1,-5,4], [-1, -3, 1, 1, 5, -10, 3, 4, -1, 2], [-1, -3, 1]]

    for ex in examples[2:]:
        print(solu.maxSubArray(ex))