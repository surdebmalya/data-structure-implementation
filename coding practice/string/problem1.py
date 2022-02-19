"""
Question:
https://leetcode.com/problems/reverse-string/submissions/

Easy
"""
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        length = len(s)
        if length==0 or length==1:
            return s
        if length%2==0:
            limit = length//2 # 4
        else:
            limit = length//2 # 2
        for i in range(limit):
            # swap index i and (-1 - i)
            temp = s[-1-i]
            s[-1-i] = s[i]
            s[i] = temp
        return s