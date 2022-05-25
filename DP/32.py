# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-01 14:15:22
'''
import sys
import os

sys.path.append("..")

class Solution:

    def longestValidParentheses2(self, s: str) -> int:    
        longest_list = [0 for _ in range(len(s))]
        max_parent = 0

        for i, c in enumerate(list(s)):
            if i == 0:
                continue
            else:
                if c == ")":
                    tmp = 0
                    if s[i - 1] == "(":
                        tmp += 2
                        start_idx = i - 2

                        if start_idx > 0:
                            count = longest_list[start_idx]
                            if count:
                                tmp += count
                        longest_list[i] = tmp
                    else:
                        start_idx = i - 1
                        if start_idx > 0:
                            count = longest_list[start_idx]
                            pre_idx = start_idx - count
                            
                            if pre_idx >= 0 and count > 0 and s[pre_idx] == "(":
                                tmp += count + 2

                                if pre_idx - 1 > 0:
                                    tmp += longest_list[pre_idx-1]

                        longest_list[i] = tmp

                    max_parent = max(max_parent, tmp)
        
        return max_parent
    def longestValidParentheses(self, s):
        dp, stack = [0]*(len(s) + 1), []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack:
                    p = stack.pop()
                    dp[i + 1] = dp[p] + i - p + 1
        return max(dp)
                            
                            
if __name__ == "__main__":
    solu = Solution()

    example = ["()()))))()()(","(()())", ")()())", "", ")(())()(()))"]

    for ex in example[0:]:
        print(solu.longestValidParentheses2(ex))