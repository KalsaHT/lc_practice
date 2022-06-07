#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-28 12:14:22
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def totalNQueens(self, n: int) -> int:
        columns = []
        right_diag, left_diag = [], []
        result = 0

        def dfs(row):
            nonlocal result
            if row == n:
                result += 1

            else:
                for i in range(n):
                    if (i in columns) or (row-i) in right_diag or (row+i) in left_diag:
                        continue

                    columns.append(i)
                    right_diag.append(row-i)
                    left_diag.append(row+i)

                    dfs(row+1)

                    columns.pop()
                    right_diag.pop()
                    left_diag.pop()

        dfs(0)
        return result

if __name__ == "__main__":
    module = Solution()
    module.totalNQueens(4)