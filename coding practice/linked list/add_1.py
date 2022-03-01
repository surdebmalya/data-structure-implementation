"""
Question:
https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

Easy
"""
#User function Template for python3

'''

class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
'''

class Solution:
    def reverse_LL(self, head):
        prev = None
        then = head.next
        while then!=None:
            head.next = prev
            prev = head
            head = then
            then = then.next
        head.next = prev
        return head
        
    def add_one(self, head):
        current = head
        prev_data = current.data
        next_data = prev_data + 1
        if (next_data//10)!=1:
            current.data = next_data
            return head
        carry = 1
        current.data = next_data%10
        prev = current
        current = current.next
        while current!=None and carry==1:
            prev_data = current.data
            next_data = prev_data + carry
            if (next_data//10)!=1:
                current.data = next_data
                return head
            carry = 1
            current.data = next_data%10
            prev = prev.next
            current = current.next
        prev.next = Node(1)
        return head
            
        
    def addOne(self,head):
        # Reverse the list
        new_head = self.reverse_LL(head)
        # Add 1 to it
        head = self.add_one(new_head)
        # Reverse again
        final_head = self.reverse_LL(head)
        return final_head
        
            
#{ 
#  Driver Code Starts
#Initial Template for Python 3

# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, value):
        if self.head is None:
            self.head = Node(value)
            self.tail = self.head
        else:
            self.tail.next = Node(value)
            self.tail = self.tail.next

def PrintList(head):
    while head:
        print(head.data,end='')
        head = head.next

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        
        num = input()
        ll = LinkedList() # create a new linked list 'll1'.
        for digit in num:
            ll.insert(int(digit))  # add to the end of the list
        
        resHead = Solution().addOne(ll.head)
        PrintList(resHead)
        print()


# } Driver Code Ends