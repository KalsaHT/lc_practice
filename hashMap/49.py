# coding=UTF-8
'''
@Author: httermin
@Date: 2020-01-03 16:27:32
'''
import sys
import os

sys.path.append("..")

from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        text_dict = {}

        for s in strs:
            _s = "".join(sorted(s))
            if text_dict.get(_s) is None:
                text_dict[_s] = [s]
            else:
                text_dict[_s].append(s)
        
        
        result = [v for _, v in text_dict.items()]
        return result

if __name__ == "__main__":
    solu = Solution()

    print(solu.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))