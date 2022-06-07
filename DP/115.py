#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-05 20:02:38
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(s) < len(t):
            return 0


        n,m = len(s), len(t)

        dp = [[0]*m for _ in range(n)]

        if s[0] == t[0]:
            dp[0][0] = 1
        
        for i in range(1, n):
            if s[i] == t[0]:
                dp[i][0] = dp[i-1][0] + 1
            else:
                dp[i][0] = dp[i-1][0]

        for i in range(1, n):
            for j in range(1, m):
                if s[i] == t[j]:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[-1][-1]

if __name__ == "__main__":
    module = Solution()
    print(module.numDistinct("babgbag", "bag"))