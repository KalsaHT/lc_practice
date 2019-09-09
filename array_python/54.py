# -*- coding: utf-8 -*-
"""
@time: 2017/8/30

@author: leilei
"""


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []

        top = left = right = bottom = 0

        result = []

        n = len(matrix) -1
        p = len(matrix[0]) -1

        i = j = 0

        while True:
            print i ,j
            # 向右走
            if i == top and j <= p - right:
                print 'right'
                if j == p - right:
                    top += 1
                result.append(matrix[i][j])
                j += 1

            # 向下走
            elif j == right and i <= n - bottom:
                print 'down'
                if i == n - bottom:
                    right += 1
                result.append(matrix[i][j])
                i += 1

            # 向左走
            elif i == bottom and j >= left:
                print 'left'
                if j == left:
                    bottom += 1
                result.append(matrix[i][j])
                j -= 1

            # 向上走
            elif j == left and i >= top:
                print 'up'
                if i == top:
                    left += 1
                result.append(matrix[i][j])
                i -= 1
            # 终止条件
            if top+bottom > n or left+right > p:
                break

        return result



s = Solution()
m = [[1, 2, 3] ,[4, 5, 6], [7, 8, 9]]
print s.spiralOrder(m)

import random