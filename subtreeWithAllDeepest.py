# Definition for a binary tree node.
from tkinter.tix import Tree


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        if not root.left and not root.right:
            return root

        # 记录父节点属性
        def findpar(node,par = None):
            if node:
                node.par = par
                findpar(node.left,node)
                findpar(node.right,node)
        findpar(root)
        root.par = None

        # 层次遍历
        queue = [root]
        import copy
        while queue:
            tmp_queue = copy.deepcopy(queue) # 保存最后一层
            for _ in range(len(queue)):
                p = queue.pop(0)
                if p.left :
                    queue.append(p.left)
                if p.right :
                    queue.append(p.right)
        minpar = tmp_queue[0]
        print('firstpar',minpar.val)
        if len(tmp_queue) == 1:
            return minpar
        def find_minpar(node, tmp_minpar):
            if node.par == tmp_minpar.par:
                return tmp_minpar.par
            if node.par == tmp_minpar: # node不可能在minpar的下一层
                return tmp_minpar

            return find_minpar(node.par,tmp_minpar.par)
        
        for i in range(1,len(tmp_queue)):
            q = tmp_queue[i]
            tmp = find_minpar(q, minpar)
            minpar = tmp
            print(minpar)
        return minpar

if __name__ == "__main__":
    l = [0, 3, 1, 4, None, 2, None, None, 6, None , 5]
    
    root = TreeNode(l[0])
    q = [root]
    for i in range(1, len(l), 2):
        tmp = q.pop(0)
        if tmp is not None:
            if l[i] is not None:
                tmp.left = TreeNode(l[i])
                q.append(tmp.left)
            if l[i+1] is not None:
                tmp.right = TreeNode(l[i+1])
                q.append(tmp.right)

    module = Solution()
    res = module.subtreeWithAllDeepest(root)
        