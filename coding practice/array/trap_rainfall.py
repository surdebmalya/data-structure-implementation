"""
Question:
https://leetcode.com/problems/trapping-rain-water/

Hard
"""
class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        if length == 1:
            return 0
        left_to_right = [-1]*length
        m = height[0] # max
        for i in range(length):
            if height[i]>m:
                m = height[i]
                left_to_right[i] = m
            else:
                left_to_right[i] = m
        right_to_left = [-1]*length
        m = height[-1] # max
        for i in range(length-1,-1,-1):
            if height[i]>m:
                m = height[i]
                right_to_left[i] = m
            else:
                right_to_left[i] = m
        water_level = [-1]*length
        for i in range(length):
            water_level[i] = min(left_to_right[i], right_to_left[i])
        water = [-1]*length
        for i in range(length):
            water[i] = water_level[i] - height[i]
        return sum(water)