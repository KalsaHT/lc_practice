#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-09 23:33:49
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        f = [[True]*n for _ in range(n)]
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                f[i][j] = (s[i] == s[j]) and f[i+1][j-1]

        dp = [0 for _ in range(n)]

        for i in range(1, n):
            if f[0][i]:
                continue
            else:
                min_split = float("inf")
                for j in range(1, i+1):
                    if f[j][i]:
                        min_split = min(min_split, dp[j-1])
                dp[i] = min_split + 1
        
        return dp[-1]

if __name__ == "__main__":
    module = Solution()
    print(module.minCut("cabababcbc"))