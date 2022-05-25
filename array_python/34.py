# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-01 17:15:24
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        start, end = 0, len(nums) - 1
        result_idx = -1
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] == target:
                result_idx = mid
                break

            if nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        
        if result_idx == -1:
            return [-1, -1]
        
        lo, hi = mid, mid

        while lo > 0 and nums[lo-1] == target:
            lo -= 1
        
        while hi+1 < len(nums) and nums[hi+1] == target:
            hi += 1
        
        return [lo, hi]

if __name__ == "__main__":
    solu = Solution()

    example = [([1], 1), ([5,7,7,8,8,10], 8), ([5,7,7,8,8,10], 6), ([5,7,8,8,8,10], 8), ([5,7,7,8,8,8,10], 8)]

    for ex, t in example:
        print(solu.searchRange(ex, t))