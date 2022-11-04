# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
203_remove_linked_list_elements on LeetCode

Solution: 
    - head handling (the following code)
    - dummy head node
    - recursion
'''

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        
        # head handling
        while head and head.val == val:
            head = head.next
        cur = head
            
        while cur:
            if cur.next and cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
