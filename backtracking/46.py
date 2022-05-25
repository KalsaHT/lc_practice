# coding=UTF-8
'''
@Author: httermin
@Date: 2019-11-19 13:17:20
'''
import sys
import os

sys.path.append("..")


class Solution(object):
    def permute(self, nums):
        result = []
        self.get_permute(result, nums, [])
        return result

    def get_permute(self, result, nums, tmp):
        if(len(nums) == 0): result.append(tmp[:])

        for i in range(len(nums)):
            tmp.append(nums[i])
            self.get_permute(result, nums[:i] + nums[i+1:], tmp)
            tmp.pop()


class Solution2(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # insert solution

        last_re, current_re = [[]], []

        for i in range(len(nums)):
            for _re in last_re:
                length_j = len(_re)
                for j in range(length_j+1):
                    tmp = _re[:j] + [nums[i]] + _re[j:]
                    current_re.append(tmp)
            last_re = current_re
            current_re = []

        return last_re

ss = Solution()
print(ss.permute([]))
                        