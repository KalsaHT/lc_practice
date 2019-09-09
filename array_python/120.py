# -*- coding: utf-8 -*-
"""
@time: 2017/8/22

@author: leilei
"""



# top - down
class Solution1(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if triangle == []:
            return 0

        min_triangle = [triangle[0]]

        for i in range(1, len(triangle)):
            sub_min = []
            for j in range(len(triangle[i])):
                if j == 0:
                    sub_min.append(triangle[i][j] + min_triangle[i-1][j])
                elif j == len(triangle[i]) - 1:
                    sub_min.append(triangle[i][j] + min_triangle[i-1][j-1])
                else:
                    sub_min.append(min(min_triangle[i-1][j-1], min_triangle[i-1][j]) + triangle[i][j])
            min_triangle.append(sub_min)
        return min(min_triangle[-1])

# buttom - up
class Solution2(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if triangle == []:
            return 0

        min_triangle = triangle[:]
        for i in range(1, len(triangle))[::-1]:
            sub_min = []
            for j in range(len(triangle[i])-1):
                sub_min.append(min(min_triangle[i][j], min_triangle[i][j+1]) + triangle[i-1][j])
            min_triangle[i-1] = sub_min

        return min_triangle[0][0]


s = Solution2()
t = [[1],
     [1, 2],
     [4, 3, 2]]
print s.minimumTotal(t)