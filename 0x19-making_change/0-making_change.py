#!/usr/bin/python3
"""
Change comes from within
Time Complexity O(n * log(n))
Space complexity O(1)
"""


def makeChange(coins, total: int) -> int:
    """
    Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.

    Args:
        coins (list): Is a list of the values of the coins in
        your possession
        total (int):  Total number to reach

    Returns:
        int: Fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    number = 0
    for i in coins:
        while i <= total:
            total -= i
            number += 1
        if total == 0:
            return number
    return -1


if __name__ == "__main__":
    makeChange(coins, total)
