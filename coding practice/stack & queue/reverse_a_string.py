"""
Question:
https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#

Easy
"""
#{ 
#Driver Code Starts

 # } Driver Code Ends
def reverse(S):
    #Add code here
    length = len(S)
    if length==1:
        return S
    stack = Stack()
    for char in S:
        stack.push(char)
    result = ""
    for i in range(length):
        result += stack.pop()
    return result
    
class Stack:
    def __init__(self):
        self.stack = []
    def isEmpty(self):
        if len(self.stack)==0:
            return True
        return False
    def push(self,value):
        self.stack.append(value)
    def pop(self):
        if self.isEmpty():
            return -1
        return self.stack.pop()

#{ 
#Driver Code Starts.
if __name__=='__main__':
    t=int(input())
    for i in range(t):
        str1=input()
        print(reverse(str1))
#} Driver Code Ends