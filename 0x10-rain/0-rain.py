#!/usr/bin/python3
""" Calculate how many square units of water will be retained
after it rains """


def rain(walls):
    """ Calculate how many square units of water will be retained
    after it rains """
    if len(walls) == 0 or type(walls) != list:
        return 0
    waterUnits = 0
    start = [0] * len(walls)
    end = [0] * len(walls)
    start[0] = walls[0]
    for i in range(1, len(walls)):
        start[i] = max(start[i - 1], walls[i])
    end[len(walls) - 1] = walls[len(walls) - 1]
    for i in range(len(walls) - 2, -1, -1):
        end[i] = max(end[i + 1], walls[i])
    for i in range(0, len(walls)):
        waterUnits += min(start[i], end[i]) - walls[i]
    return waterUnits
