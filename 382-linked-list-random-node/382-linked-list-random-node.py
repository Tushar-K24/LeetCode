import random
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head=head
        self.linklist = []
        temp = head
        while temp!=None:
            self.linklist.append(temp.val)
            temp=temp.next
        
    def getRandom(self) -> int:
        return random.choice(self.linklist)


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()