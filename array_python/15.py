# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-29 20:38:04
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        result = []

        nums = sorted(nums)
        for i, n in enumerate(nums[:-2]):
            if i > 0 and n == nums[i-1]:
                continue
            target = 0 - n 
            _result = self.twoSum_2(nums[i+1:], target)
            if _result:
                for _r in _result:
                    result.append([n] + _r)
        
        return result
        
    def twoSum(self, nums, target):
        result_dict = {}
        result = []
        for i, n in enumerate(nums):
            if n not in list(result_dict.keys()):
                result_dict[target - n] = n 
            # elif n == 0 and 0 not in nums[i+1:]:
            #     continue
            elif [target-n , n] not in result:
                result.append([target - n, n])
        return result

    def twoSum_2(self, nums, target):
        result = []

        i, j = 0, len(nums) - 1

        while(i < j):
            if nums[i] + nums[j] == target:
                result.append([nums[i], nums[j]])

                while(i<j and nums[i+1] == nums[i]):
                    i += 1
                while(i<j and nums[j] == nums[j-1]):
                    j -= 1

                i += 1
                j -= 1
                
                
            elif nums[i] + nums[j] < target:
                i += 1
            else:
                j -= 1
        
        return result
        
        

if __name__ == "__main__":
    ss = ["aabc", "bbbb", "aabc", "ab"]
    pp = ["a*bc", ".*", "c*aabc", ".*c"]    

    a = [-1,0,1,2,-1,-4]
    a1 = [0, 0,0, 0, 0]
    a2 = [-2,0,1,1,2]

    so = Solution()
    # tmp = list(zip(*[ss, pp]))
    # for i in range(len(ss)):
    #     print(so.isMatch(ss[i], pp[i]))

    print(so.threeSum(a2))