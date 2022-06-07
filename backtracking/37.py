#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-25 12:52:34
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")



class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        from copy import deepcopy

        empty = "."

        box_exists_number = [[[] for _ in range(3)] for _ in range(3)]
        horizon_exists_number = [[] for _ in range(9)]
        vertical_exists_number = [[] for _ in range(9)]

        result = []
        valid = False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == empty:
                    continue

                _box_i = i//3
                _box_j = j//3
                box_exists_number[_box_i][_box_j].append(board[i][j])

                horizon_exists_number[i].append(board[i][j])
                vertical_exists_number[j].append(board[i][j])

    
        def _valid(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, number, i, j, _box_i, _box_j):
            if number not in box_exists_matrix[_box_i][_box_j] and number not in horizon_exists_matrix[i] and number not in vertical_exists_matrix[j]:
                return True
            return False

        def _solve(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, i, j, _board):
            nonlocal valid 

            if valid:
                return
            
            if i == 9:
                _solve(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, 0, j+1, _board)
            elif j == 9:
                # result.append(deepcopy(_board))
                # board = deepcopy(_board)
                valid = True
            else:
                _box_i = i//3
                _box_j = j//3

                if _board[i][j] == empty:
                    for n in range(1, 10):
                        n = str(n)
                        if _valid(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, n, i, j, _box_i, _box_j):
                            box_exists_matrix[_box_i][_box_j].append(n)
                            horizon_exists_matrix[i].append(n)
                            vertical_exists_matrix[j].append(n)
                            _board[i][j] = n

                            _solve(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, i+1, j, _board)
                            if valid:
                                return
                            box_exists_matrix[_box_i][_box_j].pop()
                            horizon_exists_matrix[i].pop()
                            vertical_exists_matrix[j].pop()
                            _board[i][j] = empty

                else:
                    _solve(box_exists_matrix, horizon_exists_matrix, vertical_exists_matrix, i+1, j, _board)
            

        _solve(box_exists_number, horizon_exists_number, vertical_exists_number, 0, 0, board)
        # return result[0]

        # c = board
        # print(1)

if __name__ == "__main__":
    module = Solution()
                
    board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
    module.solveSudoku(board=board)