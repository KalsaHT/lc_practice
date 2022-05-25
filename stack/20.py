# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-30 15:37:03
'''
import sys
import os

sys.path.append("..")
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2:
            return False

        stack = []

        for i in range(len(s)):
            if s[i] in ["(", "[", "{"]:
                stack.append(s[i])
            elif s[i] == ")" and len(stack) and stack[-1] == "(":
                stack.pop()
            elif s[i] == "]" and len(stack) and stack[-1] == "[":
                stack.pop()
            elif s[i] == "}" and len(stack) and stack[-1] == "{":
                stack.pop()
            else:
                return False
        if len(stack) != 0:
            return False
        return True

if __name__ == "__main__":
    a = "){"

    so = Solution()

    print(so.isValid(a))