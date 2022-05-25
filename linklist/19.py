# coding=UTF-8
'''
@Author: httermin
@Date: 2019-12-29 21:54:41
'''
import sys
import os

sys.path.append("..")
import copy
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def removeNthFromEnd(self, head, n):
        fast = slow = head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head

class Solution3:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:

        if n == 0:
            return head 
        
        pointer_a = head 
        pointer_b = head 

        while n + 1 > 0:
            n -= 1
            if pointer_b is None:
                if n == -1:
                    return head.next  
                else:
                    return head 
            else:
                pointer_b = pointer_b.next
            

        if pointer_b is None:
            return head.next

        while pointer_b is not None:
            pointer_b = pointer_b.next
            pointer_a = pointer_a.next 
        
        pointer_a.next = pointer_a.next.next
        return head

class Solution2:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        tmp = head 
        count = 0
        while tmp is not None:
            count += 1
            tmp = tmp.next
        
        if count < n or n == 0:
            return head 

        _res = head 
        
        length = count - n
        if length == 0:
            return head.next
        else:
            while length > 1:
                _res = _res.next
                length -= 1
            _res.next = _res.next.next

        return head 

class Solution1:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if n == 0:
            return head
        reverse_node, length = self.reverse(head)
        tmp = reverse_node

        if length < n:
            return head 

        if n == 1:
            tmp = tmp.next
        else:      
            while n != 2:
                reverse_node = reverse_node.next
                n -= 1

            reverse_node.next = reverse_node.next.next

        result, _ = self.reverse(tmp)

        return result 
        
    def reverse(self, head: ListNode) -> (ListNode, int):
        cur = copy.deepcopy(head)
        pre = None 
        
        count = 0

        while(cur is not None):
            tmp = cur.next
            cur.next = pre
            pre = cur 
            cur = tmp
            count += 1

        return (pre, count)


if __name__ == "__main__":
    value = [1, 2]
    head = ListNode(value[0])
    tmp = head 

    # n = 1
    # while n < 5:
    #     head.next = ListNode(value[n])
    #     head = head.next
    #     n += 1


    solu = Solution()

    # new_head, count = solu.reverse(tmp)
    result = solu.removeNthFromEnd(tmp,1)

    # print(new_head, tmp, count)

    for i in range(5):
        # print(new_head.val)
        print(result.val)
        # new_head = new_head.next
        result = result.next 
