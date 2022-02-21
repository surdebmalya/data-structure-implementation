"""
Question:
https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#

Easy
"""

#User function Template for python3

class Solution:
    
    #Function to check if brackets are balanced or not.
    def ispar(self,x):
        # code here
        stack = []
        dic = {
            '[': ']',
            '{': '}',
            '(': ')'
        }
        for i in x:
            if i in dic.keys():
                stack.append(i)
            else:
                if stack==[]:
                    return False
                else:
                    upper = stack.pop()
                    # print(upper)
                    if (dic[upper]==i):
                        pass
                    else:
                        return False
        if len(stack)==0:
            return True
        else:
            return False

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

#Contributed by : Nagendra Jha


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
        #n = int(input())
        #n,k = map(int,imput().strip().split())
        #a = list(map(int,input().strip().split()))
        s = str(input())
        obj = Solution()
        if obj.ispar(s):
            print("balanced")
        else:
            print("not balanced")
# } Driver Code Ends