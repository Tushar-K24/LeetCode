# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return None
        sp, fp = head.next, head.next.next
        while fp and sp!=fp:
            sp = sp.next
            if fp.next:
                fp = fp.next
            fp = fp.next
        if not fp: return None
        sp = head
        while fp!=sp:
            fp = fp.next
            sp = sp.next
        return sp