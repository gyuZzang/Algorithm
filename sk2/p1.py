from array import array
import collections
from typing import Dict


def solution(goods):
    answer = []
    uniqueSearchKeyword = dict.fromkeys(goods, [])
    substringCounter = {}
    #하나씩 dictionary
    for good in goods:
        for char in good:
            print(char)
            if char in substringCounter:
                substringCounter[char] += 1
            else:
                substringCounter[char] = 1

    print(substringCounter)
    for good in goods:
        if len(uniqueSearchKeyword[good]):
            continue
        for char in good:
            if substringCounter[char] == 1:
                print(good, char)
                uniqueSearchKeyword[good].append(char)       

    print(uniqueSearchKeyword)
    return answer

solution(["pencil","cilicon","contrabase","picturelist"])