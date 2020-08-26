#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def water(arr, n):
    """
    Recursive function to help calculate how much water will be retained

    Arguments:
     - arr list of non-negative integers representing walls of width 1
     - n length of the list

    Returns:
     max_w How much water will be retained
    """
    max_w = 0

    for i in range(1, n - 1):
        # First find the max element in the left
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        # Then find the max element in the right
        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        # Save the max water
        max_w = max_w + (min(left, right) - arr[i])

    return max_w


def rain(walls):
    """
    Function that calculate how much water will be retained after it rains.

    Arguments:
     - walls is a list of non-negative integers.

    Return:
     Integer indicating total amount of rainwater retained.
    """
    retained = water(walls, len(walls))
    return retained
