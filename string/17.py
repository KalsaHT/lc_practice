# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-29 21:30:59
'''
import sys
import os

sys.path.append("..")
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        digit_dict = {
            1:"",
            2:"abc",
            3:"def",
            4:"ghi",
            5:"jkl",
            6:"mno",
            7:"pqrs",
            8:"tuv",
            9:"wxyz",
        }

        if not digits: return ""

        result = []

        for s in digits:
            int_digit = int(s)
            if not result:
                result = list(digit_dict[int_digit])
            else:
                tmp = []
                for _res in result:
                    tmp.extend([_res + e for e in list(digit_dict[int_digit])])
                result = tmp
        return result

if __name__ == "__main__":
    s = "23"

    solution = Solution()

    print(solution.letterCombinations(s))