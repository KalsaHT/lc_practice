# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-01 15:42:05
'''
import sys
import os

sys.path.append("..")

from typing import List
class Solution:
    def search(self, nums: List[int], target: int) -> int:

        start, end = 0, len(nums) - 1

        while start <= end:
            mid = (end + start) // 2
            if nums[mid] == target:
                return mid
            
            if nums[mid] < nums[end]:
                if target <= nums[end] and target > nums[mid]:
                    start = mid + 1
                else:
                    end = mid - 1
            else:
                if target >= nums[start] and target < nums[mid]:
                    end = mid -1
                else:
                    start = mid + 1
        return -1
        
    def bisearch(self, nums, target):
        
        start, end = 0, len(nums) - 1

        while start < end:
            mid = (end - start) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                end -= 1
            else:
                start += 1
        return -1

if __name__ == "__main__":
    solu = Solution()

    example = [([4,5,6,7,0,1,2], 0), ([4,5,6,7,0,1,2], 3)]

    for ex, t in example:
        print(solu.search(ex, t))