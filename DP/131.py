#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-09 23:01:26
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        f = [[True]*n for _ in range(n)]

        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                f[i][j] = (s[i] == s[j]) and f[i+1][j-1]

        res = []
        ans = []

        def dfs(i):
            if i == n:
                res.append(ans[:])
                return
            else:
                for j in range(i, n):
                    if f[i][j]:
                        ans.append(s[i:j+1])
                        dfs(j+1)
                        ans.pop()

        
        dfs(0)
        return res

if __name__ == "__main__":
    module = Solution()
    print(module.partition("aabb"))