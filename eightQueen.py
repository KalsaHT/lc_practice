# coding=UTF-8
'''
@Author: httermin
@Date: 2019-10-31 11:52:23
'''
import sys
import os

sys.path.append("..")


def isAvailable(row_list, col):
    # row_list before row
    row = len(row_list)
    for k, col_k in enumerate(row_list):
        if (col_k == col) or (row - k) == (col - col_k) or (row - k) == (col_k - col):
            return False
    return True


# 回溯法

def find(n):
    queen = [-1] * (n + 1)
    row = 0
    count = 0

    queen[row] = 0
    
    while row >= 0:
        if row < n and queen[row] < n:
            if isAvailable(queen[:row], queen[row]):
                row += 1
                queen[row] = 0
            else:
                queen[row] += 1
        else:
            if row >= n:
                count += 1
            row -= 1
            queen[row] += 1
    return count

print(find(8))