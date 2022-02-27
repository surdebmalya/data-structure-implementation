"""
Question:
https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

Medium
"""
#User function Template for python3
class Solution:
     
    #Function to find if there exists a triplet in the 
    #array A[] which sums up to X.
    def find3Numbers(self,A, n, X):
        # Your Code Here
        A.sort()
        if len(A)<3 or sum(A)<X:
            return False
        for i in range(n):
            if (n - i)>=3:
                sub_sum = X-A[i]
                ptr1 = i+1
                ptr2 = n-1
                while ptr1<ptr2:
                    if (A[ptr1] + A[ptr2])==sub_sum:
                        return True
                    elif (A[ptr1] + A[ptr2])>sub_sum:
                        ptr2 -= 1
                    else:
                        ptr1 += 1
        return False
            

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n,X=map(int,input().strip().split())
        A=list(map(int,input().strip().split()))
        ob=Solution()
        if(ob.find3Numbers(A,n,X)):
            print(1)
        else:
            print(0)
# } Driver Code Ends