# -*- coding: utf-8 -*-
"""
@time: 2017/10/16

@author: leilei
"""


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        index = self.search1(nums, target)
        if index == -1:
            return False
        else:
            return True

    def search1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1

        if len(nums) == 1:
            if nums[0] == target:
                return 0
            else:
                return -1

        rotate_index = -1
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                rotate_index = i

        if rotate_index == -1:
            return self.bisearch(nums, 0, len(nums) - 1, target)

        if target < nums[0]:
            index = self.bisearch(nums, rotate_index + 1, len(nums) - 1, target)
        else:
            index = self.bisearch(nums, 0, rotate_index, target)

        return index

    def bisearch(self, nums, low, high, target):
        '''nums - list[int]'''
        if high < low:
            return -1

        mid = low + (high - low) / 2
        print mid

        if nums[mid] == target:
            return mid
        else:
            if nums[mid] < target:
                low = mid + 1
                return self.bisearch(nums, low, high, target)
            else:
                high = mid - 1
                return self.bisearch(nums, low, high, target)
