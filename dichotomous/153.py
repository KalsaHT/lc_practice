#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-11 15:26:15
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 2 and nums[0] < nums[1]:
            return nums[0]
        self.nums = nums

        index = self.part_find(0, len(nums)-1)
        return nums[index]
    

    def part_find(self, low, high):
        # print(low, high)
        if high - low < 1:
            return -1

        if high - low == 1:
            if self.nums[low] > self.nums[high]:
                return high
            else:
                return -1

        mid = low + (high - low) // 2
        if self.nums[mid] > self.nums[high]:
            res = self.part_find(mid, high)
        elif self.nums[mid] < self.nums[high]:
            res = self.part_find(low, mid)
        else:
            res = self.part_find(low, high-1)
        # left = self.part_find(low, mid)
        # right = self.part_find(mid, high)

        if res == -1:
            return 0

        return res

if __name__ == "__main__":
    module = Solution()
    print(module.findMin([2,2,2,0,1]))