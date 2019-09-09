# -*- coding: utf-8 -*-
"""
@time: 2017/9/11

@author: leilei
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def buildTree1(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        val = preorder[0]
        tree = TreeNode(preorder[0])
        idx = inorder.index(val)
        #print val, idx
        if len(preorder) == 1:
            return tree
        if idx != 0:
            tree.left = self.buildTree(preorder[1:1+idx], inorder[:idx])
        if idx!=len(preorder):
            tree.right = self.buildTree(preorder[1+idx:], inorder[idx+1:])
        return tree

    def buildTree(self, preorder, inorder):
        if inorder:
            ind = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[ind])
            print root.val
            root.left = self.buildTree(preorder, inorder[0:ind])
            root.right = self.buildTree(preorder, inorder[ind + 1:])
            return root

preorder = [1,2,3]
inorder = [2,1,3]
s = Solution()
s.buildTree(preorder, inorder)

