# -*- coding: utf-8 -*-
"""
Segment TreeによるRange Minimum Queryの実装
蟻本準拠です

Verified: AOJ DSL_2_A
"""

class RangeMinQuery:
    inf = float("inf")
    def __init__(self, N):
        self.n = 1
        while self.n < N: self.n *= 2
        self.dat = [self.inf] * (2 * self.n - 1)

    def update(self, k, x):
        k += self.n - 1
        self.dat[k] = x
        while (k > 0):
            k = (k - 1) / 2
            self.dat[k] = min(self.dat[2 * k + 1], self.dat[2 * k + 2])

    # [a, b); call query(a, b)
    def query(self, a, b, k = 0, l = 0, r = -1):
        if r == -1: r = self.n
        if r <= a  or b <= l: return self.inf
        if a <= l and r <= b: return self.dat[k]

        vl = self.query(a, b, 2 * k + 1, l, (l + r) / 2)
        vr = self.query(a, b, 2 * k + 2, (l + r) / 2, r)
        return min(vl, vr)
