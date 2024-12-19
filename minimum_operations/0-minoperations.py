#!/usr/bin/python3
"""
finds minimum operations
"""


def minOperations(n):
    if n < 2:
        return 0  # Cannot achieve n < 2
    
    operations = 0
    factor = 2
    
    while n > 1:
        while n % factor == 0:
            operations += factor  # Add operations: factor pastes + 1 copy all
            n //= factor
        factor += 1
    
    return operations

# Example usage
print(minOperations(9))  # Expected output: 6
