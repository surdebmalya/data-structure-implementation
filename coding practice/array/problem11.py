"""
Question:
https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

Easy
"""
#User function Template for python3

class Solution:

    def findMinDiff(self, A,N,M):
        A.sort()
        minimum = A[M-1] - A[0]
        for i in range(1, len(A)):
            try:
                temp = A[M-1 + i] - A[i]
                if temp<minimum:
                    minimum = temp
            except:
                return minimum
        return minimum
                
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        N = int(input())
        A = [int(x) for x in input().split()]
        M = int(input())


        solObj = Solution()

        print(solObj.findMinDiff(A,N,M))
# } Driver Code Ends