# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-02 11:15:17
'''
import sys
import os

sys.path.append("..")
from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        # bucket sort

        if not nums:
            return 1
        # for i in range(len(nums)):
        #     while nums[i] <= len(nums) and nums[i] > 0 and nums[nums[i] - 1] != nums[i]:
        #         nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(len(nums)):

            while nums[i] <= len(nums) and nums[i] > 0 and nums[nums[i]-1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i in range(len(nums)):
            if i + 1 != nums[i]:
                return i + 1
        
        return len(nums) + 1

class Solution2:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if len(nums) == 0: return 1
        nums = sorted(nums)

        if nums[0] > 1 or nums[-1] <=0:
            return 1

        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] > 1 and nums[i-1]>0:
                return nums[i-1] + 1
            elif nums[i] > 1 and nums[i-1] <= 0:
                return 1
        
        return nums[-1] + 1

if __name__ == "__main__":
    solu = Solution()

    examples = [[1,2,0], [3,4,-1,1], [7,8,9,11,12], [0, 4, 3, -2], [-3, -4, -1], [3, 4, 5, 6], [-1, 1000], [1, 1]]

    for ex in examples[:]:
        print(solu.firstMissingPositive(ex))