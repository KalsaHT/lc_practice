# -*- coding: utf-8 -*-
"""
@time: 2017/8/21

@author: leilei
"""
from collections import defaultdict

class Solution1(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        sums = [0]

        # 累加
        for i, n in enumerate(nums, 1):
            sums.append(sums[i - 1] + n)

        print sums

        # 两指针
        slow = 0
        # fast

        count = 0

        # 对累加进行循环
        for slow in range(len(sums)):
            for fast in range(slow+1, len(sums)):
                if sums[fast] - sums[slow] == k:
                    print fast, slow
                    count += 1

        return count



class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        map_sum = defaultdict(int)
        map_sum[0] = 0
        #print map_sum

        # 累加
        sums = [0]

        for i, n in enumerate(nums, 1):
            sums.append(sums[i-1] + n)

        count = 0
        for s in sums:
            #print map_sum[s-k]
            count += map_sum[s-k]
            #print count, s
            map_sum[s] += 1

        #print map_sum

        return count


nums = [1,2 ,3]
k = 3

s = Solution()
print s.subarraySum(nums, k)