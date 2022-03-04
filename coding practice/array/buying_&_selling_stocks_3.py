"""
Question:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Hard
"""
import sys

class Solution:    
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if length==1:
            return 0
        left = [-1]*length
        left[0]=0
        MIN = prices[0]
        profit=0
        for i in range(1, length):
            if prices[i]<MIN:
                MIN=prices[i]
            else:
                if prices[i]-MIN>profit:
                    profit=prices[i]-MIN
            left[i]=max(left[i-1], profit)
        
        right=[-1]*length
        right[-1]=0
        MAX=prices[-1]
        profit=0
        for i in range(length-2, -1, -1):
            if prices[i]>MAX:
                MAX=prices[i]
            else:
                if MAX-prices[i]>profit:
                    profit=MAX-prices[i]
            right[i]=max(right[i+1], profit)
        
        MAX = -sys.maxsize
        for i in range(length):
            if left[i]+right[i]>MAX:
                MAX=left[i]+right[i]
        return MAX