#215. Kth Largest Element in an Array

from typing import List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        ans = 0
        heapq.heapify(nums)
        smallest = len(nums) - k + 1
        for _ in range(smallest):
            ans = heapq.heappop(nums)

        return ans