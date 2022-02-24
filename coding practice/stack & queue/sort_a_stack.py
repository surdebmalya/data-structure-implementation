"""
Question:
https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

Easy
"""
class Solution:
    # your task is to complete this function
    # function sort the stack such that top element is max
    # funciton should return nothing
    # s is a stack
    def sorted(self, s):
        # Code here
        length = len(s)
        space = [-1] * length
        for i in range(length):
            space[i] = s.pop()
        space.sort()
        for i in space:
            s.append(i)

#{ 
#  Driver Code Starts
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.sorted(arr)
        for e in range(len(arr)):
            print(arr.pop(), end=" ")
        print()


# } Driver Code Ends