#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-30 19:51:44
'''
from operator import mod
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def isNumber(self, s: str) -> bool:

        valid_nums = [str(i) for i in range(10)] + ["e", "E", "+", "-", "."]

        contain_e = False
        for i, c in enumerate(s):
            if c not in valid_nums:
                return False

            if i == 0 and c in ["e", "E"]:
                return False

            if c in ['e', "E"]:
                contain_e = True
                if s[i-1] not in valid_nums[:10]:
                    return False

            elif c == ".":
                if i > 0 and contain_e:
                    return False
            
            elif c in ["+", "-"]:
                # contain_min = True
                if i != 0 and s[i-1] not in ["e", "E"]:
                    return False

        return True

if __name__ == "__main__":
    module = Solution()
    print(module.isNumber("-123.456e789"))
                