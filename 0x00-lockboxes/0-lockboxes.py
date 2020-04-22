#!/usr/bin/python3
"""
Lock Boxes Algorithm for interview
"""


def canUnlockAll(boxes):
    """
     Function to check if the box can be unlocked
    """
    stack = [0]
    unlock = [0] * len(boxes)
    unlock[0] = 1

    if len(boxes) == 0:
        return True

    if not isinstance(boxes, list):
        return False

    while stack:
        box = stack.pop()
        for k in boxes[box]:
            if k > 0 and k < len(boxes) and unlock[k] == 0:
                unlock[k] = 1
                stack.append(k)

    return all(unlock)
