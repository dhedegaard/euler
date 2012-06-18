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

def prime_fac(num, primes):
    result = []
    while num > 2 and num not in primes:
        for i in primes:
            if num % i == 0:
                num /= i
                result.append(i)
                break
        print "wtf: %d" % num
    result.append(num)
    return result

input = 600851475143
print "generating primes..."
primes = eratosthenes(int(math.ceil(math.sqrt(input))))
print "reversing primes vector"
primes.reverse()
print "finding primefactors..."
result = prime_fac(input, primes)
print result
