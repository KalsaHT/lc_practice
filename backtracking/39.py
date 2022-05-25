# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-01 17:38:37
'''
import sys
import os

sys.path.append("..")

from typing import List
from copy import deepcopy

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        tmp = []
        self.getSum(result, candidates, 0, target, tmp)
        return result

    def getSum(self, result, candidates, start, target, tmp):
        if target == 0 and tmp: result.append(tmp[:])
        if target < 0: return 
        
        i = start
        while i < len(candidates):
            
        # for i in range(start, len(candidates)):
            tmp.append(candidates[i])
            if candidates[i] == 0:
                i += 1
            if i < len(candidates):
                self.getSum(result, candidates, i, target-candidates[i], tmp)
            else:
                result.append(tmp[:])
            tmp.pop()
            i += 1

if __name__ == "__main__":
    solu = Solution()
    examples = [([2,3,6,7], 7), ([2,3,5], 8), ([], 1), ([0], 0)]

    for ex, t in examples[:]:
        print(solu.combinationSum(ex, t))