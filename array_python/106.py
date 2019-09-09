# -*- coding: utf-8 -*-
"""
@time: 2017/9/11

@author: leilei
"""


#Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if inorder:
            idx = inorder.index(postorder.pop(-1))
            tree = TreeNode(inorder[idx])
            tree.right = self.buildTree(inorder[idx+1:], postorder)
            tree.left = self.buildTree(inorder[:idx], postorder)
            return tree