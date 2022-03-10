"""
Question:
https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1#

Medium
"""
#User function Template for python3

class Solution:
    
    #Function to find the smallest positive number missing from the array.
    def missingNumber(self,arr,n):
        #Your code here
        value = n+2
        for i in range(n):
            if arr[i]<=0 or arr[i]>n:
                arr[i]=value
        for i in range(n):
            if abs(arr[i])<=n:
                arr[abs(arr[i])-1]=-abs(arr[abs(arr[i])-1])
        firstMissing=1
        for i in range(n):
            if arr[i]<0:
                firstMissing+=1
            else:
                return firstMissing
        return firstMissing

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
            print(ob.missingNumber(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends