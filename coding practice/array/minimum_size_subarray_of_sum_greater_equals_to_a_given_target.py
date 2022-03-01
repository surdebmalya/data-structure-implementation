"""
Question:
https://leetcode.com/problems/minimum-size-subarray-sum/

Medium
"""
import sys
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if sum(nums)<target:
            return 0
        MIN = sys.maxsize
        ptr1=0
        ptr2=0
        length = len(nums)
        sub_sum = nums[0]
        while ptr2!=length:
            if sub_sum<target:
                ptr2+=1
                if ptr2!=length:
                    sub_sum+=nums[ptr2]
            elif sub_sum>=target:
                size = ptr2-ptr1+1
                if size<MIN:
                    MIN = size
                sub_sum-=nums[ptr1]
                ptr1+=1
        return MIN