#46. Permutations
from typing import List
from itertools import permutations

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return permutations(nums, len(nums))