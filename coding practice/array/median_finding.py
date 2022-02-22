"""
Question:
https://practice.geeksforgeeks.org/problems/find-the-median0527/1

Easy
"""

class Solution:
    def find_median(self, v):
        # First sort - O(n * logn)
        v.sort()
        # Find median of the sorted array - O(1)
        if len(v) % 2 == 0:
            median = (v[len(v)//2] + v[(len(v)//2)-1])//2
        else:
            median = v[len(v)//2]
        return median

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        v = list(map(int,input().split())) 
        ob = Solution();
        ans = ob.find_median(v)
        print(ans)
# } Driver Code Ends
