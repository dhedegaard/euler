#!/usr/bin/python

def is_divisible(num, cap):
    for i in xrange(1, cap + 1):
        if num % i != 0:
            return False
    return True

cap = 20
a = cap
while not is_divisible(a, cap):
    a += cap
print a
