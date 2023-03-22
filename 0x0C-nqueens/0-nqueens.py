#!/usr/bin/python3
"""0. N queens """

import sys

if (len(sys.argv) != 2):
    print("Usage: nqueens N")
    exit(1)

try:
    N = int(sys.argv[1])
except Exception:
    print("N must be a number")
    exit(1)

if (N < 4):
    print("N must be at least 4")
    exit(1)


def solveNQueens(n):
    pass
