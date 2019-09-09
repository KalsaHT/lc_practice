# -*- coding: utf-8 -*-
"""
@time: 2017/10/19

@author: leilei
"""


# class Solution(object):
#     def rob(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if not nums:
#             return 0
#         if len(nums) < 3:
#             money = max(nums)
#             return money
#         money = max(nums[0] + nums[2], nums[1])
#
#         return money + self.rob(nums[3:])
class Solution:
    def rob(self, nums):
        last, now = 0, 0

        for i in nums:
            print now
            last, now = now, max(last + i, now)


        return now

s = Solution()
print s.rob([1, 2, 3, 4, 5, 6])