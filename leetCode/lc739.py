# 739 Daily Temperatures
from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0 for i in range(len(temperatures))]
        day = 0
        for tem in temperatures:
            while len(stack):
                if stack[-1]['tem'] < tem:
                    popDay = stack.pop(-1)['day']
                    res[popDay] = day - popDay
                else: break
            stack.append({'tem': tem, 'day': day}) #push
            day += 1
        return res
        


    