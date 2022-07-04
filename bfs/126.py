#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-08 19:05:25
'''
import sys
import os
from typing import List, Tuple, Dict
from collections import defaultdict 

sys.path.append("..")

class Solution:
    
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []

        if len(wordList) < 1:
            return []

        res = []

        nearby_word_map = defaultdict(list)
        for word in wordList:
            for i in range(len(word)):
                nearby_word_map[word[:i] + "_" + word[i+1:]].append(word)

        queue = [(beginWord, [beginWord])]
        visited = set()

        while queue:
            _visited = set()
            
            length = len(queue)
            for _ in range(length):
                word, tmp = queue.pop(0)

                if word == endWord:
                    res.append(tmp)
                else:
                    for i in range(len(word)):
                        _w = word[:i] + "_" + word[i+1:]
                        for w in nearby_word_map[_w]:
                            if w in visited:
                                continue
                            if w not in tmp:
                                queue.append([w, tmp + [w]])
                                _visited.add(w)

            visited = visited | _visited
            if len(res) > 0:
                break
        
        return res

if __name__ == "__main__":
    module = Solution()
    print(module.findLadders("hit", "cog", ["hot","dot","dog","lot","log","cog"]))