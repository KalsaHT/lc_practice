# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-24 12:00:29
'''
import sys
import os

sys.path.append("..")
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        is_palindrome_table = [[False for _ in range(length)] for _ in range(length)]

        max_lens = 1
        start_idx = 0

        for i in range(length):
            is_palindrome_table[i][i] = True

            if i<length-1 and s[i] == s[i+1]:
                is_palindrome_table[i][i+1] = True
                max_lens = 2
                start_idx = i

        
        start_lens = 3

        for lens in range(start_lens, length+1):
            for i in range(length - lens + 1):
                j = i + lens - 1

                if s[i] == s[j] and is_palindrome_table[i+1][j-1]:
                    is_palindrome_table[i][j] = True
                    if max_lens < lens:
                        max_lens = lens
                        start_idx = i 
        
        return s[start_idx:max_lens+start_idx]

if __name__ == "__main__":
    ss = Solution()

    ex = ["a", "", "aa", "aba", "aabbaaba"]

    for _e in ex:
        print(ss.longestPalindrome(_e))
        