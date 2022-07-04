#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-11 16:05:25
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

from itertools import chain
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        
        if len(nums) < 2:
            return 0
        
        if len(nums) == 2:
            return abs(nums[0] - nums[1])
        
        sort_nums = self.radixSort(nums)

        max_dist = 0
        for i, n in enumerate(sort_nums[:-1]):
            max_dist = max(max_dist, sort_nums[i+1] - n)

        return max_dist

    
    def radixSort(self, nums):
        nums = [str(n) for n in nums]
        sort_array = [[] for _ in range(11)]

        tail_index = 1
        while len(sort_array[0]) != len(nums):
            sort_array = [[] for _ in range(11)]

            for i in range(len(nums)):
                
                str_num = nums[i]
                if len(str_num) < tail_index:
                    sort_array[0].append(str_num)
                else:
                    lst_n = int(str_num[-tail_index])
                    sort_array[int(lst_n) + 1].append(str_num)

            nums = list(chain(*sort_array))
            tail_index += 1

        return [int(n) for n in nums]
                    

if __name__ == "__main__":
    module = Solution()
    print(module.maximumGap([1,3, 100]))
        