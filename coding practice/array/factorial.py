"""
Question:
https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

Medium
"""
#User function Template for python3

class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class Solution:
    def factorial(self, N):
        if N==1:
            return [1]
        num = N
        val = num%10
        head = Node(val)
        num //= 10
        init = head
        while num!=0:
            init.next = Node(num%10)
            init = init.next
            num //=10
        end = init
        
        carry = 0
        for number in range(N-1, 1, -1):
            front = head
            while front!=None:
                prev_value = front.val
                next_value = (prev_value*number)+carry
                front.val = next_value%10
                carry = next_value//10
                front = front.next
            if carry!=0:
                number=carry
                init = end
                while number!=0:
                    init.next = Node(number%10)
                    init = init.next
                    number //=10
                end = init
            carry=0
        s = []
        while head!=None:
            s.append(head.val)
            head = head.next
        s.reverse()
        return s

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.factorial(N);
        for i in ans:
            print(i,end="")
        print()
    
# } Driver Code Ends