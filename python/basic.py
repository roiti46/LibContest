# -*- coding:utf-8 -*-
"""
雑多な関数のまとめ。そのうち整理したい。
"""

# GCD and LCM
def gcd(a, b):
    while b: a, b = b, a % b
    return a

def lcm(a, b):
    return a / gcd(a, b) * b

# 素数判定
def isprime(n):
    if (n < 2): return False
    if (n == 2): return True
    if (n % 2 == 0): return False
    for i in xrange(3, int(n ** 0.5) + 1, 2):
        if n % i == 0: return False
    return True


# エラトステネスのふるい
def prime_sieve(int n):
    p = [1] * (n + 1)
    p[0] = p[1] = 0
    p[4::2] = [0] * len(p[4::2])
    for i in xrange(3, int(n ** 0.5) + 1, 2):
        if p[i]:
            p[2 * i::i] = [0] * len(p[2 * i::i])
    return p


# 素因数分解
def prime_factorize(int n):
    res = []
    i = 2
    while i * i <= n:
        cnt = 0
        while n % i == 0:
            n /= i
            cnt += 1
        if cnt > 0: res.append([i, cnt])
        i += 1
    if n > 1: res.append([n, 1])
    return res


#最長部分増加列. need bisect.
#Verified: AOJ DPL_1_D
def lis(A):
    n = len(A)
    L = [0] * n
    L[0] = A[0]
    length = 1

    for i in xrange(1, n):
        if L[length - 1] < A[i]:
            L[length] = A[i]
            length += 1
        else:
            L[bisect.bisect_left(L[:length], A[i])] = A[i]

    return length
