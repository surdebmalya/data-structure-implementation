"""
Question:
https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1#

Easy
"""
#User function Template for python3
import sys

class Solution:
    def find_min(self, d):
        arr = [d['0'], d['1'], d['2']]
        MAX = max(arr)
        MIN = min(arr)
        return (MAX - MIN + 1)
        
    def smallestSubstring(self, S):
        # Code here
        d = {'0':-1,'1':-1,'2':-1}
        MIN = sys.maxsize
        for index, char in enumerate(S):
            if d['0']!=-1 and d['1']!=-1 and d['2']!=-1:
                temp_min = self.find_min(d)
                if temp_min<MIN:
                    MIN=temp_min
            d[char]=index
        if d['0']!=-1 and d['1']!=-1 and d['2']!=-1:
            temp_min = self.find_min(d)
            if temp_min<MIN:
                MIN = temp_min
        else:
            return -1
        return MIN

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.smallestSubstring(S)
        
        print(ans)



# } Driver Code Ends