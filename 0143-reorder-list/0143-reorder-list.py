# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        fast = head.next
        slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        curr = slow.next
        slow.next = None
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        l1 = head
        l2 = prev
        while l2:
            temp = l1.next
            l1.next = l2
            temp2 = l2.next
            l2.next = temp
            l1 = temp
            l2 = temp2