#347. Top K Frequent Elements
from typing import List
from queue import PriorityQueue

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numCount = {}
        result = []
        pq = PriorityQueue() 
        for num in nums:
            if num in numCount:
                numCount[num] += 1
            else:
                numCount[num] = 1
            
        for num in numCount:
            pq.put((len(nums)-numCount[num], num))
       
        for i in range(k):
            num = pq.get()[1]
            result.append(num)

        return result