"""
Question:
https://leetcode.com/problems/k-closest-points-to-origin/

Medium
"""
import heapq, math

class Solution:
    def distance(self, dx, dy):
        s = dx**2 + dy**2
        return math.sqrt(s)
        
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        for index, point in enumerate(points):
            dist_from_origin = self.distance(point[0], point[1])
            heapq.heappush(h, (dist_from_origin, index))
        results = heapq.nsmallest(k, h)
        output = []
        for i in results:
            output.append(points[i[1]])
        return output