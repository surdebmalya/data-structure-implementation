"""
Question:
https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#

Easy
"""
#User function Template for python3

class Solution:
    ##Complete this function
    # Function to check if given number n is a power of two.
    def isPowerofTwo(self,n):
        ##Your code here
        count1=0
        while n!=0:
            rem=n%2
            if rem==1:
                count1+=1
            n = n//2
        if count1==1:
            return True
        return False

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math


def main():
    
    T=int(input())
    
    while(T>0):
        
        
        n=int(input())
        ob=Solution()
        if ob.isPowerofTwo(n):
            print("YES")
        else:
            print("NO")
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends