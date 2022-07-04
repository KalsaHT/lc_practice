#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-11 16:24:58
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]

        

        