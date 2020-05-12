#!/usr/bin/python3
"""
Function minOperations
"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    Arguments:
     - n (int): Given a number
    Returns:
     Returns an integer
    """
    if type(n) is not int or n < 2:
        return 0

    factor = []
    i = 2
    while i <= n:
        if n % i == 0:
            factor.append(i)
            n = n / i
        else:
            i += 1

    return sum(factor)
