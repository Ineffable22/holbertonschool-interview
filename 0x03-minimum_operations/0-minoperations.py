#!/usr/bin/python3
"""
This calculates the fewest number of operations needed
to result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    Return:
    sum of their prime factors of each number
    """
    if (n <= 1):
        return (0)
    mul = 2
    total = 0
    while (n != 1):
        if n % mul == 0:
            n /= mul
            total += mul
            mul = 2
        else:
            mul += 1
    return total


if __name__ == '__main__':
    minOperations(n)

"""
Legend:
CA = CopyAll
P = Paste
______________________________________________________________________________
| Number | Times | Resolution                                                |
|============================================================================|
| 1      |   1   | H                                                         |
| 2      |   2   | Prime number                                              |
| 3      |   3   | Prime number                                              |
| 4      |   4   | H => CA => P => 2H => CA => P => 4H                       |
| 5      |   5   | Prime number                                              |
| 6      |   5   | H => CA => P => 2H => P => 3H => CA => P => 6H            |
| 7      |   7   | Prime number                                              |
| 8      |   6   | H => CA => P => 2H => CA => P => 4H => CA => P => 8H      |
| 9      |   6   | H => CA => P => 2H => P => 3H => CA => P => 6H => P => 9H |
| 10     |   7   | H => CA => P => 2H => P => 3H => P => 4H => P => 5H => CA |
|                | => P => 10H                                               |
| 11     |   11  | Prime number                                              |
| 12     |   7   | H => CA => P => 2H => P => 3H => CA => P => 6H => CA => P |
|                | => 12H                                                    |
| 13     |   13  | Prime number                                              |
| 14     |   9   | H => CA => P => 2H => P => 3H => P => 4H => P => 5H => P  |
|                | => 6H => P => 7H => CA => P => 14H                        |
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
Note:
According to the pattern they are the sum of their prime factors of each number
"""
