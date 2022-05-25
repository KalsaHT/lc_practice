# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-31 15:38:09
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        i = len(nums) - 1

        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1
        
        if i == 0:
            nums.reverse()
            return nums

        i -= 1

        j = len(nums) - 1

        while j > 0 and nums[j] <= nums[i]:
            j -= 1

        nums[i], nums[j] = nums[j], nums[i]
        
        index = i
        n = len(nums) - index - 1
        
        for i in range(n//2):
            nums[index + i + 1], nums[index + i + n- 2*i] = nums[index + i + n- 2*i], nums[index + i + 1]
        
        return nums
            
if __name__ == "__main__":
    solu = Solution()
    t = [[1, 2, 3], [3, 2, 1], [5, 2, 4, 3, 2, 1], [4,2,0,2,3,2,0], [1,3,2], [5, 1, 1]]

    for m in t[0:]:
        print(solu.nextPermutation(m))