#!/usr/bin/env python3
"""
finds minimum operations
"""
import sympy as sp


def find_prime_factors(n, list_of_factors=[], min_prime=1):
    if n == 1:
        return list_of_factors
    possible_primes = sp.primerange(min_prime + 1, n + 1)
    checker = n
    for i in possible_primes:
        while n % i == 0:
            n /= min_prime
            list_of_factors.append(i)
        if checker != n:
            min_prime = i
            break
    find_prime_factors(n, list_of_factors, i)



def minOperations(n):
    initial_mult = 0
    op = 0
    # if uneven H => c => p = HH => p = HHH  
    return op