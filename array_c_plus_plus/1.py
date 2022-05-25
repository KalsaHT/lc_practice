# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-22 15:57:41
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def twoSum(self, num, target):
        if len(num) < 2:
            return [-1, -1]
        
        num_dict = {}

        for i, n in enumerate(num):
            if num_dict.get(n) is None:
                num_dict[n] = i

        for i, n in enumerate(num):
            diff = target - n

            posi = num_dict.get(diff)
            if posi is not None and :
                return [i, posi]

        return [-1, -1]


    def twoSum_loop(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
                
        if len(nums) < 2:
            return [-1, -1]

        length = len(nums)

        for i in range(length):
            diff = target - nums[i]
            for j in range(i+1, length):
                if nums[j] == diff:
                    return [i, j]
        
        return [-1, -1]


if __name__ == "__main__":
    
    test_set = [([2, 7, 11, 15], 9), 
    ([15, 2, 7, 9], 9),
    ([1, 1, 3, 2, 1], 2),
    ([], 0)]

    ss = Solution()

    for num, t in test_set:
        print(ss.twoSum(num, t))