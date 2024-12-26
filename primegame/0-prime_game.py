#!/usr/bin/python3
"""
This is some documentation
"""


def isWinner(x, nums):
    """
    Decides who wins the primegame
    """
    winner = [0, 0]
    for round in range(x):
        if x < 2:
            winner[1] += 1
            continue

        primes = [True] * nums[round]+1
        primes[0], primes[1] = False

        p = 2
        while p * p <= nums[round]:
            if primes(p):
                for i in range(p * p, nums[round], p):
                    primes[i] = False
            p += 1
        
        prime_numbers = [i for i in range(nums[round] + 1) if primes[i]]

        #winner.append(0) if len(prime_numbers) % 2 == 0 else winner.append(1)
        if len(prime_numbers) % 2 == 0:
            winner[1] += 1
        else:
            winner[0] += 1
        #winner[1] if len(prime_numbers) % 2 == 0 else winner[0] += 1

    if winner[0] > winner[1]:
        return 'Maria'
    elif winner[1] > winner[0]:
        return 'Ben'
    else:
        return None
