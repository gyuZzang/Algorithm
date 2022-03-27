# 743. Network Delay Time
from turtle import distance
from typing import List

def networkDelayTime(times: List[List[int]], n: int, k: int) -> int:
    maxDistance = 101
    distances = [[maxDistance]*n for _ in range(n)]

    def updateDelayTime(start, mid):
        for end in range(n):
            if start != end and distances[mid][end] < maxDistance and distances[start][end] > distances[start][mid] + distances[mid][end]:
                distances[start][end] = distances[start][mid] + distances[mid][end]
                updateDelayTime(start, end)

    for start, end, time in times:
        distances[start-1][end-1] = time
    
    for i in range(n):
        distances[i][i] = 0
        if distances[k-1][i] < maxDistance and k-1 != i:
            updateDelayTime(k-1, i)
    
    answer = max(distances[k-1])

    if answer >= maxDistance:
        return -1
    return answer

networkDelayTime([[2,1,1],[2,3,1],[3,4,1]], 4, 2)
