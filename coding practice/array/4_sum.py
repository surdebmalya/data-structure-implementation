"""
Question:
https://leetcode.com/problems/4sum/

Medium
"""
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        length = len(nums)
        res = []
        if length<=3:
            return res
        nums.sort()
        for i in range(0, length-3):
            for j in range(i+1, length-2):
                sub_target = target - nums[i] - nums[j]
                ptr1 = j+1
                ptr2 = length-1
                while ptr1<ptr2:
                    if (nums[ptr1]+nums[ptr2])==sub_target:
                        temp_arr = [nums[i], nums[j], nums[ptr1], nums[ptr2]]
                        if temp_arr not in res:
                            res.append(temp_arr)
                        ptr1 += 1
                        ptr2 -= 1
                    elif (nums[ptr1]+nums[ptr2])<sub_target:
                        ptr1 += 1
                    else:
                        ptr2 -= 1
        return res