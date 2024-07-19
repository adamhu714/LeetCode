# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # prev = None
        # curr = head
        # while curr:
        #     temp = curr.next
        #     curr.next = prev
        #     prev = curr
        #     curr = temp
        # return prev
        head = self.recursion(head)
        return head
        
    def recursion(self, curr):
        if not curr:
            return None
        newHead = curr
        if curr.next:
            newHead = self.recursion(curr.next)
            curr.next.next = curr
        curr.next = None
        return newHead