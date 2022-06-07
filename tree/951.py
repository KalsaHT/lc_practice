#-*-coding:utf-8-*-
'''
@Author: llei
@Date: 2022-06-02 19:52:21
'''
from re import T
import sys
import os
from typing import List, Tuple, Dict

sys.path.append("..")

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def flipEquiv(self, root1: TreeNode, root2: TreeNode) -> bool:
            
            if root1 is None and root2 is None:
                return True

            if root1 is None or root2 is None:
                return False

            if root1.val != root2.val:
                return False

            if root1.left is None or root1.right is None:
                if root1.right is None:
                    tmp = root1.left
                    root1.left = root1.right
                    root1.right = tmp

            if root1.left is None:
                if root2.left is not None and root2.right is not None:
                    return False

                if root1.right is None:
                    if root2.left is None and root2.right is None:
                        return True
                    else:
                        return False

                elif root2.left is None:
                    
                    if root2.right is None or root1.right.val != root2.right.val:
                        return False
                    else:
                        return self.flipEquiv(root1.right, root2.right)
                elif root2.right is None:
                    if root2.left is None or root1.right.val != root2.left.val:
                        return False
                    else:
                        return self.flipEquiv(root1.right, root2.left)
            
            else:
                if root2.left is None or root2.right is None:
                    return False
                if root1.left.val == root2.left.val and root1.right.val == root2.right.val:
                    return self.flipEquiv(root1.left, root2.left) and self.flipEquiv(root1.right, root2.right)
                elif root1.left.val == root2.right.val and root1.right.val == root2.left.val:
                    return self.flipEquiv(root1.right, root2.left) and self.flipEquiv(root1.left, root2.right)
                
            return False

if __name__ == "__main__":
    a = [1,2,3,4,5,6,None,None,None,7,8]