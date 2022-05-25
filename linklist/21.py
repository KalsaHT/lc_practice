# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-30 15:48:07
'''
import sys
import os

sys.path.append("..")
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None: return l2
        if l2 is None: return l1

        if l1.val > l2.val:
            start = l2
            l2 = l2.next
        else:
            start = l1
            l1 = l1.next
        
        # l1 is the smaller one

        tmp = start
        
        while (l1 is not None) or (l2 is not None):
            
            if l1 is None:
                tmp.next = l2
                l2 = l2.next
            elif l2 is None:
                tmp.next = l1
                l1 = l1.next
            else:
                if l1.val < l2.val:
                    tmp.next = l1
                    l1 = l1.next
                else:
                    tmp.next = l2
                    l2 = l2.next
            tmp = tmp.next
        return start
        