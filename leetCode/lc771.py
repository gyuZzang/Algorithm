#771 Jewels and Stones

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        stoneCount = {}
        result = 0
        for stone in stones:
            if stone in stoneCount :
                stoneCount[stone] += 1
            else:
                stoneCount[stone] = 1
        
        for jewel in jewels:
            if jewel in stoneCount:
                result += stoneCount[jewel]
        
        return result
