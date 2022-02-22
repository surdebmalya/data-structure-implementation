"""
Question:
https://leetcode.com/problems/rectangle-overlap/

Easy
"""
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # finding all the cases where the rectangles can be overlapped!
        if(rec1[1]>=rec2[3])or(rec2[1]>=rec1[3])or(rec1[2]<=rec2[0])or(rec1[0]>=rec2[2]):
            return False
        return True