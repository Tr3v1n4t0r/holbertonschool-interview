#!/usr/bin/python3
"""
Determines if all the locked boxes can be opened
from gathering keys from other boxes
"""


def canUnlockAll(boxes):
    open = {0}
    for i, box in enumerate(boxes):
        for key in box:
            if key != i:
                open.add(key)
    for i in range(len(boxes)):
        if i not in open:
            return False
    return True
