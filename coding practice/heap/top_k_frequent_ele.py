"""
Question:
https://leetcode.com/problems/top-k-frequent-elements/

Medium
"""
import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for num in nums:
            try:
                d[num] += 1
            except:
                d[num] = 1
        h = []
        for i in d.keys():
            heapq.heappush(h, (d[i], i))
        result = heapq.nlargest(k, h)
        output = []
        for i in result:
            output.append(i[1])
        return output