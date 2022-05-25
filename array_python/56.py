# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-05 19:14:43
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:return intervals
        sorted_intervals = sorted(intervals, key=lambda x:x[0])

        result = [sorted_intervals[0][:]]
        count = 1
        length = len(intervals)
        while count < length:
            value_second_start = sorted_intervals[count][0]
            if value_second_start <= result[-1][1]:
                if sorted_intervals[count][1] <= result[-1][1]:
                    pass
                else:
                    result[-1] = [result[-1][0], sorted_intervals[count][1]]
            else:
                result.append(sorted_intervals[count][:])
            count += 1

        return result

if __name__ == "__main__":
    solu = Solution()

    examples = [[[1,3],[2,6],[8,10],[15,18]], [[1,4],[4,5]]]

    for ex in examples:
        print(solu.merge(ex))