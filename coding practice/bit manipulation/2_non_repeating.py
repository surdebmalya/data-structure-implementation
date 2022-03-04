"""
Question:
https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#

Easy
"""
#User function Template for python3

class Solution:
    def singleNumber(self, nums):
        # Code here
        res=0
        for i in nums:
            res ^= i
        index=0
        while res!=0:
            rem=res%2
            if rem==1:
                break
            res=res//2
            index+=1
        temp = 1<<index
        num1, num2 = 0, 0
        for num in nums:
            if num & temp==0:
                num1^=num
            else:
                num2^=num
        if num1<num2:
            return [num1, num2]
        return [num2, num1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        v = list(map(int,input().split()))
        ob = Solution();
        ans = ob.singleNumber(v)
        for i in ans:
            print(i, end = " ")
        print()

# } Driver Code Ends