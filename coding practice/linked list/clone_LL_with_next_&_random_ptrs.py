"""
Question:
https://leetcode.com/problems/copy-list-with-random-pointer/

Medium
"""
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head==None:
            return None
        front=head
        while front:
            tempNode = Node(front.val)
            tempNode.next=front.next
            front.next=tempNode
            front=front.next.next
        
        item=head
        while item:
            if item.random:
                item.next.random = item.random.next
            item = item.next.next            
        
        head=head.next
        link=head
        while link.next:
            link.next=link.next.next
            link=link.next
            
        return head