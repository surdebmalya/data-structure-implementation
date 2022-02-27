"""
Question:
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

Medium
"""
#User function Template for python3
import sys

class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,N):
        ##Your code here
        MAX = -sys.maxsize
        count = 0
        positive_found = False
        for i in range(N):
            if arr[i]>=0:
                positive_found = True
                count += arr[i]
            elif arr[i]<0 and positive_found:
                if (count + arr[i]) > 0:
                    if count>MAX:
                        MAX = count
                    count += arr[i]
                else:
                    if count>MAX:
                        MAX = count
                        count = 0
                        positive_found = False
                    else:
                        count = 0
                        positive_found = False
            else:
                if arr[i]>MAX:
                    MAX = arr[i]
        if count==0 and MAX<0:
            return MAX
        elif count>MAX:
            MAX = count
        return MAX
                
#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            
            print(ob.maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends