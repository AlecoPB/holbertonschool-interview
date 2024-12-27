#!/usr/bin/python3
"""
Prime Game Solution without Turn Simulation
"""


def isWinner(x, nums):
    """
    Determines the winner of a series of prime games.
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)
    primes = sieve_of_eratosthenes(max_n)

    # Precompute the cumulative count of primes up to each number
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if primes[i] else 0)

    # Track wins for Maria and Ben
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_count[n] % 2 == 1:  # Odd number of primes: Maria wins
            maria_wins += 1
        else:  # Even number of primes: Ben wins
            ben_wins += 1

    # Determine overall winner
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None


def sieve_of_eratosthenes(n):
    """
    Generates a list of primes up to n using the Sieve of Eratosthenes.
    """
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n ** 0.5) + 1):
        if is_prime[p]:
            for multiple in range(p * p, n + 1, p):
                is_prime[multiple] = False

    return is_prime
