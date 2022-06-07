#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-05-30 20:09:25
'''
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        seperate_words = []
        count = 0
        tmp = []
        for w in words:
            if count + len(w) > maxWidth:
                seperate_words.append(tmp)
                tmp = []
                count = 0
                tmp.append(w)
                count = len(w) + 1
            else:
                count += len(w) + 1
                tmp.append(w)

        if len(tmp) > 0:
            seperate_words.append(tmp)

        result = []

        for i, word_list in enumerate(seperate_words):
            if len(word_list) == 1:
                result.append(word_list[0] + " "*(maxWidth - len(word_list[0])))
            elif i == len(seperate_words) -1:
                result.append(" ".join(word_list) + " "*(maxWidth - len(" ".join(word_list))))
            else:
                remaind = maxWidth-sum([len(s) for s in word_list[:-1]]) - len(word_list[-1])
                residual = remaind%(len(word_list) -1)
                divide = remaind // (len(word_list) -1)
                
                tmp = ""
                for w in word_list[:-1]:
                    tmp += w + " "*divide
                    tmp += " " if residual>0 else ""
                    residual -= 1

                tmp += word_list[-1]
                result.append(tmp)

        return result

if __name__ == "__main__":
    module = Solution()
    
    module.fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16)