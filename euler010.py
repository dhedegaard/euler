#!/usr/bin/python
import math

def eratosthenes(cap):
    a = []
    for i in xrange(0, cap + 1):
        a.append(i % 2 == 1)
    for i in xrange(3, int(math.ceil(math.sqrt(cap + 1))), 2):
        if a[i] == True:
            for j in xrange(i * i, cap + 1, i):
                a[j] = False
    primes = []
    for i in xrange(2, len(a)):
        if a[i]:
            primes.append(i)
    return primes

primes = eratosthenes(2000000)
print sum(primes)
