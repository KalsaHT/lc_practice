# -*- coding: utf-8 -*-
"""
@time: 2017/9/14

@author: leilei
"""


class Solution(object):

    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return

        h = len(nums)

        while h:
            for i in xrange(h, len(nums)):
                while i>0:
                    if nums[i] < nums[i-h]:
                        tmp = nums[i]
                        nums[i] = nums[i-h]
                        nums[i-h] = tmp
                    i -= h
            h /= 2
        return

s = Solution()
nums = [0]
print s.sortColors(nums)