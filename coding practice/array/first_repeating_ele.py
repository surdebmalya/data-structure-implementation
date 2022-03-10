"""
Question:
https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/#

Easy
"""
#User function Template for python3

class Solution:
    #Function to return the position of the first repeating element.
    def firstRepeated(self,arr, n):
        #arr : given array
        #n : size of the array
        found={}
        index=n+1
        for i in range(n):
            if arr[i] in found:
                if index>found[arr[i]]:
                    index=found[arr[i]]
            else:
                found[arr[i]]=i+1
        if index==n+1:
            return -1
        return index

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        
        arr=[int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.firstRepeated(arr, n))
# } Driver Code Ends