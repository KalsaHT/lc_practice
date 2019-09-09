# -*- coding: utf-8 -*-
"""
@time: 2017/10/16

@author: leilei
"""


class Solution_iter(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        item = [[]]
        for i in nums:
            item += [j + [i] for j in item]

        return item


s = Solution_iter()
print s.subsets([1,2, 2])






























