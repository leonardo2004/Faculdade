# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummyOutput = ListNode()
        current = dummyOutput
        carry = aux = 0

        while l1 or l2 or carry:
            l1aux = l1.val if l1 else 0
            l2aux = l2.val if l2 else 0
            aux = l1aux + l2aux + carry
            newNode = ListNode()
            current.next = newNode
            current = current.next
            if aux >= 10:
                carry = aux//10
                current.val = aux%10
            else:
                carry = 0
                current.val = aux
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummyOutput.next

