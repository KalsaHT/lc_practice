# -*- coding: utf-8 -*-
"""
@time: 2017/8/26

@author: leilei
"""

class Solution1(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board:
            return False

        for i in range(len(board)):
            for j in range(len(board[i])):
                if self.DFS(i, j, board, word):
                    return True
        return False

    def DFS(self, i, j, board, word):
        # 若word无字，则回归True
        if len(word)==0:
            return True
        # 超过边界，回归False
        if i<0 or i>=len(board) or j<0 or j>=len(board[i]) or word[0]!=board[i][j]:
            # print word[0]
            # print i, j
            return False
        # 若word第一个词不等于board[i][j]，回归False
        # if word[0] != board[i][j]:
        #     return False
        # 在边界内，进行再次DFS判断
        tmp = board[i]
        tmp1 = list(board[i])
        tmp1[j] = '#'
        board[i] = ''.join(tmp1)
        result = self.DFS(i-1, j, board, word[1:]) \
                 or self.DFS(i+1, j, board, word[1:]) \
                 or self.DFS(i, j-1, board, word[1:]) \
                 or self.DFS(i, j+1, board, word[1:])

        board[i] = tmp
        return result

class Solution():
    def exist(self, board, word):
        if not board:
            return False
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False

    # check whether can find word, start at (i,j) position
    def dfs(self, board, i, j, word):
        if len(word) == 0:  # all the characters are checked
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or word[0] != board[i][j]:
            return False
        tmp = board[i]
        tmp1 = list(board[i])
        tmp1[j] = '#'
        board[i] = ''.join(tmp1)
        # first character is found, check the remaining part
       # avoid visit agian
        # check whether can find "word" along one direction
        res = self.dfs(board, i + 1, j, word[1:]) or self.dfs(board, i - 1, j, word[1:]) \
              or self.dfs(board, i, j + 1, word[1:]) or self.dfs(board, i, j - 1, word[1:])
        board[i] = tmp
        return res

s = Solution1()
a = ["ab"]
b = "ba"
print s.exist(a, b)