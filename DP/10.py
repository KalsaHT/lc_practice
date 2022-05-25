# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-26 11:52:40
'''
import sys
import os

sys.path.append("..")

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(p) == 0: return not s

        first_match = bool(s) and s[0] == p[0] or p[0] == "."

        if len(p) >= 2 and p[1] == "*":
            return self.isMatch(s, p[2:]) or first_match and self.isMatch(s[1:], p)
        else:
            return first_match and self.isMatch(s[1:], p[1:])
        

if __name__ == "__main__":
    ss = ["aabc", "bbbb", "aabc", "ab"]
    pp = ["a*bc", ".*", "c*aabc", ".*c"]    

    so = Solution()
    # tmp = list(zip(*[ss, pp]))
    for i in range(len(ss)):
        print(so.isMatch(ss[i], pp[i]))

    