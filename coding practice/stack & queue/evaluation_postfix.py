"""
Question:
https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#

Easy
"""
#User function Template for python3

class Stack:
    def __init__(self):
        self.stack = []
    def isEmpty(self):
        if len(self.stack)==0:
            return True
        return False
    def push(self, value):
        self.stack.append(value)
    def pop(self):
        if self.isEmpty():
            return -1
        ele = self.stack[-1]
        self.satck = self.stack.pop()
        return ele
    def top(self):
        if self.isEmpty():
            return -1
        return self.stack[-1]

class Solution:
    #Function to evaluate a postfix expression.
    def evaluatePostfix(self, S):
        #code here
        operators = ['+', '-', '*', '/']
        s = Stack()
        for i in S:
            if i in operators:
                var2 = s.pop()
                var1 = s.pop()
                if i=='+':
                    s.push(var1+var2)
                elif i=='*':
                    s.push(var1*var2)
                elif i=='-':
                    s.push(var1-var2)
                else:
                    s.push(var1//var2)
            else:
                s.push(int(i))
        return s.pop()

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

# This code is contributed by Nikhil Kumar Singh(nickzuck_007)

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
    
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        S = input()
        obj = Solution()
        print('{0:g}'.format(float(obj.evaluatePostfix(S))))
# } Driver Code Ends