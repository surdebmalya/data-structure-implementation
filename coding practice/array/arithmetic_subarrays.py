"""
Question:
https://leetcode.com/problems/arithmetic-subarrays/

Medium
"""
class Solution:
    def isArithmetic(self, arr):
        length=len(arr)
        if length==1 or length==2:
            return True
        arr.sort()
        diff=None
        for i in range(1, length):
            temp_diff=arr[i]-arr[i-1]
            if diff==None:
                diff=temp_diff
            elif diff!=temp_diff:
                return False
        return True
        
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        answer=[]
        for i in range(len(l)):
            starting=l[i]
            ending=r[i]
            temp=nums[starting:ending+1]
            answer.append(self.isArithmetic(temp))
        return answer