# 015 3sum
from typing import List

class Solution:
     def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        if(len(nums) < 3):
            return []
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                targetNum = - (nums[i] + nums[j])
                if(targetNum in nums[j+1:] and not [nums[i],nums[j],targetNum] in res):
                    res.append([nums[i],nums[j],targetNum])
                    
        return res