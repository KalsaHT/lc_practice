# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-23 12:39:13
'''
import sys
import os

sys.path.append("..")
class Solution(object):

    def lengthOfLongestSubstring(self, s):
        max_length = 0
        posi_dict = {}

        last_index = -1

        for i, c in enumerate(s):

            posi_c = posi_dict.get(c)

            if posi_c is not None:
                last_index = max(last_index, posi_c)
            
            max_length = max(max_length, i - last_index)
            posi_dict[c] = i 

        return max_length

    def lengthOfLongestSubstring_loop(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxlength = 0
        substr = ""

        for c in s:

            try:
                position = substr.index(c)
            except ValueError:
                position = None

            if position is None:
                substr += c 
            else:
                substr = substr[position+1:] + c

            maxlength = max(maxlength, len(substr))
        return maxlength

if __name__ == "__main__":
    s = ["abcabcbb", "bbbbb", "pwwkew", "", "aabaab!bb"]

    solution = Solution()

    for t in s:
        print(solution.lengthOfLongestSubstring(t))