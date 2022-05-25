# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-31 19:05:06
'''
import sys
import os

sys.path.append("..")
# Definition for singly-linked list.

from typing import List

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:

        new_listnode = ListNode(0)
        tmp = new_listnode

        while self.is_none(lists):
            tmp.next = ListNode(self.compare(lists))
            tmp = tmp.next
        return new_listnode.next
    
    def compare(self, list_nodes):
        min_index, min_val = -1, float("inf")
        
        for i, _node in enumerate(list_nodes):
            if _node is not None and _node.val < min_val:
                min_index = i 
                min_val = _node.val
        
        list_nodes[min_index] = list_nodes[min_index].next

        return min_val

    
    def is_none(self, list_nodes):

        for _node in list_nodes:
            if _node is not None:
                return True
        return False

class Solution2:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # if len(lists) == 0: return ListNode(0)
        new_listnode = ListNode(0)

        list_nodes = []

        for list_node in lists:
            while list_node is not None:
                list_nodes.append(list_node)
                list_node = list_node.next
        
        list_nodes = sorted(list_nodes, lambda x:x.val)

        tmp = new_listnode
        for _list_node in list_nodes:
            tmp.next = _list_node
            tmp = tmp.next
        return new_listnode.next
            