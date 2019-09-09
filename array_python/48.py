# -*- coding: utf-8 -*-
"""
@time: 2017/8/29

@author: leilei
"""

import copy
class Solution1(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        if not matrix:
            return

        matrix_ = copy.deepcopy(matrix)

        n = len(matrix)
        p = len(matrix[0])

        for i in range(n):
            for j in range(p):
                matrix[j][n-i-1] = matrix_[i][j]


        return matrix

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        # 转置
        for i in range(n):
            for j in range(i, n):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[j][i]
                matrix[j][i] = tmp

        # 左右折叠对调
        for i in range(n):
            for j in range(n/2):
                tmp = matrix[i][j]
                matrix[i][j] = matrix[i][n-j-1]
                matrix[i][n-j-1] = tmp

        return matrix

m = [[1,2,3],[4,5,6],[7,8,9]]
s = Solution()
print s.rotate(m)