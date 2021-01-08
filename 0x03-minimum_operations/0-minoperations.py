#!/usr/bin/python3
"""
Calculates the minimum number of operations for getting 'n' characters using
only copy/paste functions
"""


def minOperations(n):
    """Returns the number of prime factors of n"""
    if (n <= 1):
        return 0
    num = n
    i = 2
    total = 0
    while (i <= num // 2):
        if (num % i == 0):
            total += i
            num //= i
        else:
            i += 1
    return total + num
