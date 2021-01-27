#!/usr/bin/python3
"""
Prime Game
"""


def isprime(n):
    """
    Helper function to determine if a number is prime
    Arguments:
     - n: number to check if it is prime
    Returns:
     A boolean
    """
    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def delete_numbers(n, nums):
    """
    Helper function that delete numbers in the helper list
    """
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """
    Function that determine who the winner of each game is.

    Arguments:
     - x is the number of rounds and nums is an array of n

    Returns:
     The name of the player that won the most rounds
     If the winner cannot be determined, return None
    """

    if not nums or x < 1:
        return None

    nums.sort()
    winner = False
    Maria = 0
    Ben = 0
    for game in range(x):
        nums2 = list(range(1, nums[game] + 1))
        turn = 0

        while True:
            change = False

            for i, n in enumerate(nums2):
                if n > 1 and isprime(n):
                    delete_numbers(n, nums2)
                    change = True
                    turn += 1
                    break

            if change is False:
                break

        if turn % 2 != 0:
            Maria += 1
        else:
            Ben += 1

    if Maria == Ben:
        return None

    if Maria > Ben:
        return "Maria"

    return "Ben"
