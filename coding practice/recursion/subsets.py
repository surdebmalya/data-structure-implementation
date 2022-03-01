"""
Question:
https://leetcode.com/problems/subsets/

Medium
"""
result = []

class Solution:
    def printF(self, nums, n, ds, index):
        global result
        if index>=n:
            result.append(ds.copy()) # Always use .copy()
            return
        ds.append(nums[index])
        self.printF(nums, n, ds, index+1)
        ds.pop()
        self.printF(nums, n, ds, index+1)
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        global result
        result = []
        self.printF(nums, len(nums), [], 0)
        return result