#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.

    Arguments:
     - coins is a list of the values of the coins in your possession
     - total is an integer with the total of coins

    Return:
     Fewest number of coins needed to meet total
        - If total is 0 or less, return 0
        - If total cannot be met by any number of coins you have, return -1
    """

    if total <= 0:
        return 0

    if coins is None or coins == []:
        return -1

    coins = sorted(coins, reverse=True)
    tot_coins = 0

    for coin in coins:
        if coin <= total:
            tot_coins += int(total / coin)
            total = total % coin

        if total == 0:
            return tot_coins

    return -1
