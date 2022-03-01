"""
Question:
https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

Easy
"""
#User function Template for python3

class Solution:
    def getPairsCount(self, arr, n, k):
        # code here
        d={}
        count=0
        for ele in arr:
            if (k-ele) in d:
                count += d[k-ele]
            if ele in d:
                d[ele] += 1
            else:
                d[ele] = 1
        return count

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getPairsCount(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends