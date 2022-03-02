"""
Question:
https://leetcode.com/problems/combination-sum/

Medium
"""
class Solution:
    result = []
    
    def find_all(self, arr, index, n, target, subSum, ds):
        if index==n or subSum>target:
            return
        if subSum==target:
            self.result.append(ds.copy())
            return
        # pick the element
        ds.append(arr[index])
        self.find_all(arr, index, n, target, subSum+arr[index], ds)
        
        ds.pop()
        self.find_all(arr, index+1, n, target, subSum, ds)
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.result = []
        self.find_all(candidates, 0, len(candidates), target, 0, [])
        return self.result