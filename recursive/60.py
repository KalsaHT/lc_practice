#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-30 12:40:03
'''
from curses.ascii import SO
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        result = []
        stop = False
        nums = list(range(1, n+1))

        def dfs(tmp, nums):
            nonlocal stop
            if len(nums) == 0:
                result.append(tmp)
                if len(result) == k:
                    stop = True
                return
            else:
                if stop:
                    return
                for i, n in enumerate(nums):
                    dfs(tmp + [n], nums[:i] + nums[i+1:])
                    if stop:
                        return

        dfs([], nums)

        return "".join([str(t) for t in result[-1]])
        
if __name__ == "__main__":
    module = Solution()
    module.getPermutation(4, 9)