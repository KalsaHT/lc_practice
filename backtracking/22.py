# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-31 09:52:19
'''
import sys
import os

sys.path.append("..")

class Solution:
    def generateParenthesis(self, n: int):
        result = []
    
        def gen_pa(s, left_num, right_num):
            if left_num == right_num and len(s) == 2*n:
                result.append(s)
            elif right_num>left_num or left_num>n or right_num>n:
                pass
            else:
                gen_pa(s + "(", left_num+1, right_num)
                gen_pa(s + ")", left_num, right_num+1)
        gen_pa("", 0, 0)
        return result

if __name__ == "__main__":
    solu = Solution()

    for i in [0, 1, 2]:
        print(solu.generateParenthesis(i))