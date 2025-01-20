#!/usr/bin/python3
"""
This is some documentation
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given total.

    :param coins: List of the values of the coins in your possession.
    :param total: The target amount.
    :return: Fewest number of coins needed to meet the total (-1 if failed)
    """
    if total <= 0:
        return 0

    # Initialize the dp array where dp[i] is the minimum
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: 0 coins are needed to make a total of 0

    # Fill the dp array
    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If the total cannot be reached, return -1
    return dp[total] if dp[total] != float('inf') else -1
