"""
Question:
https://leetcode.com/problems/find-the-duplicate-number/submissions/

Easy
"""
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        length = len(nums)
        n = length - 1
        d = {}
        for i in range(n+1):
            d[i+1] = 0
        for i in range(length):
            if d[nums[i]]==0:
                d[nums[i]]+=1
            else:
                return nums[i]