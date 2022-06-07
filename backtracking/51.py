#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-28 10:30:20
'''
from operator import le
import sys
import os
from turtle import right
from typing import List, Tuple, Dict

sys.path.append("..")

# 超时
class Solution1:
    def solveNQueens(self, n: int) -> List[List[str]]:
        from copy import deepcopy
        empty = "."
        queen = "Q"

        empty_chess = ["."*n for _ in range(n)]
        result = []

        def valid(chess, i, j):
            if queen in chess[i]:
                return False

            if queen in [chess[k][j] for k in range(n)]:
                return False

            slash = [chess[i+k][j+k] for k in range(1, n-max(i, j))]
            slash += [chess[i-k-1][j-k-1] for k in range(0, min(i, j))]

            slash += [chess[i+k][j-k] for k in range(1, min(n-i-1, j) + 1)]
            slash += [chess[i-k][j+k] for k in range(1, min(i, n-j-1) + 1)]
            
            if queen in slash:
                return False

            return True


        def dfs(chess, i, j, count):
            if count == n:
                result.append(deepcopy(chess))
                return 

            if i == n:
                dfs(chess, 0, j+1, count)
                return

            if j == n:
                return

            if valid(chess, i, j):
                chess[i] = chess[i][:j] + queen + chess[i][j+1:]
                count += 1
                dfs(chess, i+1, j, count)
                chess[i] = empty*n
                count -= 1
            
            dfs(chess, i+1, j, count)

        dfs(empty_chess, 0, 0, 0)

        return result

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        columns = set()
        right_diag, left_diag = set(), set()  # 引用 从左上到右下的斜对角线下标相减一致， 从左下到右上的斜对角线下标相加一致
        queen = [-1] * n
        result = []

        def generate():
            tmp = []
            tmp_row = ["."] * n
            for i, j in enumerate(queen):
                tmp_row[j] = "Q"
                tmp.append("".join(tmp_row))
                tmp_row = ["."] * n

            result.append(tmp)
        
        def dfs(row):
            if row == n:
                generate()
                return

            else:
                for i in range(n):
                    if (i in columns) or (row-i in right_diag) or (row+i in left_diag):
                        continue
                    columns.add(i)
                    right_diag.add(row-i)
                    left_diag.add(row+i)
                    queen[row] = i

                    dfs(row+1)
                    columns.remove(i)
                    right_diag.remove(row-i)
                    left_diag.remove(row+i) 
        
        dfs(0)

        return result
if __name__ == "__main__":
    module = Solution()
    module.solveNQueens(4)