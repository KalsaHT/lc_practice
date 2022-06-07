#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-28 22:26:25
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        dp = [[False for _ in range(m + 1)] for _ in range(n + 1)]
        dp[0][0] = True
        for i in range(1, m+1):
            if p[i-1] == "*":
                dp[0][i] = dp[0][i-1]

        for i in range(1, n+1):
            _s_idx = i - 1

            for j in range(1, m+1):
                _p_idx = j - 1

                if p[_p_idx] == "?":
                    dp[i][j] = dp[i-1][j-1]

                elif p[_p_idx] == s[_s_idx]:
                    dp[i][j] = dp[i-1][j-1]

                elif p[_p_idx] == "*":
                    dp[i][j] = dp[i-1][j-1] or dp[i][j-1] or dp[i-1][j]
        print(dp)
        return dp[n][m]

if __name__ == "__main__":
    module = Solution()
    module.isMatch("aa", "a*")