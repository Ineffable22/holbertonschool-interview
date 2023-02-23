#!/usr/bin/python3
"""
Change comes from within
Dynamic programming
Time Complexity O(n * m)
Space complexity O(total)
"""


def makeChange(coins: list, total: int) -> int:
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
    INF = float('inf')
    dp = [INF] * (total + 1)
    dp[0] = 0
    for i in range(1, total + 1):
        for j in range(len(coins)):
            if coins[j] <= i:
                dp[i] = min(dp[i], dp[i - coins[j]] + 1)
            else:
                break
    return dp[total] if dp[total] != INF else -1


if __name__ == "__main__":
    coins = [507, 500, 300, 200, 6, 5, 4, 3]
    total = 1413
    print(makeChange(coins, total))
