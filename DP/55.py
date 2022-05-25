# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-05 18:46:28
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        is_jump = [False for _ in range(len(nums))]
        
        if len(nums) == 0:
            return False

        is_jump[0] = True

        for i in range(1, len(nums)):
            count = 1
            for j in list(range(0, i))[::-1]:
                if is_jump[j] and nums[j] >= count:
                    is_jump[i] = True
                    break
                count += 1
        
        return is_jump[-1]

if __name__ == "__main__":
    examples = [[2,3,1,1,4], [3,2,1,0,4], [2, 0, 3, 1, 1, 1, 0]]

    solu = Solution()

    for ex in examples:
        print(solu.canJump(ex))