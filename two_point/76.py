#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-31 15:09:26
'''
import sys
import os
from turtle import right
from typing import List, Tuple, Dict

sys.path.append("..")

# 超时
class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        if s == t:
            return t

        from copy import deepcopy

        left_point, tmp_point, right_point = 0, 0, 0
        result = []

        tmp_t = list(t)
        for i in range(len(s)):
            if s[i] in tmp_t:
                left_point = i
                tmp_t.remove(s[i])
                break

        exists = []
        remainder = []
        if len(tmp_t) == 0:
            return t

        while left_point < len(s) - len(t) + 1:
            stop = False
            
            if right_point == 0:
                start = left_point + 1
            else:
                start = right_point + 1

            if start == len(s):
                break

            for j in range(start, len(s)):
                
                if s[j] in t:
                    exists.append(j)
                    if s[j] in tmp_t:
                        tmp_t.remove(s[j])
                    else:
                        remainder.append(s[j])

                if len(tmp_t) == 0:
                    result.append(s[left_point:j+1])
                    tmp_t = [s[left_point]]
                    left_point = exists[0]
                    exists = exists[1:]
                    right_point = j

                    while tmp_t[0] in remainder and len(exists) > 0:
                        remainder.remove(tmp_t[0])
                        result.append(s[left_point:right_point+1])
                        tmp_t = [s[left_point]]
                        left_point = exists[0]
                        exists = exists[1:]
                        
                    stop = True
                    break
            
            if not stop:
                left_point += 1
                right_point = j

        result = sorted(result, key=lambda x:len(x))
        if result == []:
            return ""

        return result[0]


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        pass

if __name__ == "__main__":
    module = Solution()
    print(module.minWindow("bbabb", "baba"))