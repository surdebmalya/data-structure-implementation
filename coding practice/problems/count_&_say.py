"""
Question:
https://leetcode.com/problems/count-and-say/

Medium
"""
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        say = "1"
        current = "1"
        for i in range(2, n+1):
            temp_str = ""
            count = 0
            for each_char in say:
                if current==each_char:
                    count+=1
                else:
                    temp_str+=str(count)+current
                    current=each_char
                    count=1
            
            say = temp_str + str(count) + current
            current = say[0]
        return say