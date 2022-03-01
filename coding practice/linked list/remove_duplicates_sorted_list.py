"""
Question:
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Medium
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        visited = set()
        current = head
        Next = head.next
        while Next!=None:
            if Next.val==current.val:
                Next = Next.next
                visited.add(current.val)
            else:
                current.next = Next
                current = Next
                Next = Next.next
        if current.next != None:
            current.next = None
        print(visited)
        
        # find front
        ptr = head
        while ptr!=None:
            if ptr.val not in visited:
                front = ptr
                break
            else:
                ptr = ptr.next
        if ptr==None:
            return None
        new_front = front
        new_next = front.next
        while new_next!=None:
            if new_next.val not in visited:
                new_front.next = new_next
                new_front = new_next
                new_next = new_next.next
            else:
                new_next = new_next.next
        if new_front.next!=None:
            new_front.next = None
        return front