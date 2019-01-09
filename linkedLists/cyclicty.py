# Problem 7.3 Python Version

"""
Return True if cycle in linked list else False 
"""
# FROM LEETCODE
"""
Basic understanding is to set up a fast runner and 
a slow runner, if the fast runner reaches the slow one 
then we have a cycle else we dont 
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Cycles(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        try:
            slow = head
            fast = head.next
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False
        


