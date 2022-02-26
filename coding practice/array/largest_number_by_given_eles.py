"""
Question:
https://leetcode.com/problems/largest-number/

Medium
"""
class Solution:    
    def merging(self, nums, starting, end, mid):
        i = starting
        j = mid+1
        temp_arr = []
        flag=True
        while flag:
            if i==mid+1:
                # copy all j
                for j_temp in range(j, end+1):
                    temp_arr.append(nums[j_temp])
                    flag=False
            elif j==end+1:
                # copy all i
                for i_temp in range(i, mid+1):
                    temp_arr.append(nums[i_temp])
                    flag=False
            else:
                s1 = nums[i]
                s2 = nums[j]
                num1 = int(str(s1)+str(s2))
                num2 = int(str(s2)+str(s1))
                if (num1<num2): # done for octal case removal
                    temp_arr.append(s2)
                    j+=1
                else:
                    temp_arr.append(s1)
                    i+=1
        sub_index = 0
        for index in range(starting, end+1):
            nums[index] = temp_arr[sub_index]
            sub_index += 1
    
    def partition(self, nums, starting, end):
        if starting<end:
            mid = (starting+end)//2
            self.partition(nums, starting, mid)
            self.partition(nums, mid+1, end)
            return self.merging(nums, starting, end, mid)
    def largestNumber(self, nums: List[int]) -> str:
        if len(nums)==1:
            return str(nums[0])
        i = 0
        j = len(nums)-1
        self.partition(nums, i, j)
        result = ""
        for s in nums:
            result += str(s)
        result = int(result)
        result = str(result) # for [0,0] case
        return result