# -*- coding: utf-8 -*-
"""
0-indexed BIT (Binary Indexed Tree)
"""

class BIT:
    def __init__(self, size):
        self.size = size
        self.bit = [0] * (size + 1)

    # sum [0, i)
    def sum(self, i):
        i += 1
        s = 0
        while (i > 0):
            s += self.bit[i]
            i -= i & -i
        return s

    # sum [i, j)
    def sum_sec(self, i, j):
        return self.sum(j) - self.sum(j)

    def add(self, i, x):
        i += 1
        while (i <= self.size):
            self.bit[i] += x
            i += i & -i
