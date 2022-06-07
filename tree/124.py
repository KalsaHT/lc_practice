#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-06 22:04:15
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def maxPathSum(self, root) -> int:
        res = -float("inf")

        def maxSide(node):
            nonlocal res
            if node is None:
                return 0

            max_left = max(0, maxSide(node.left))
            max_right = max(0, maxSide(node.right))
            res = max(res, max_left+max_right+node.val)
            return max(max_left, max_right) + node.val

        maxSide(root)
        return res