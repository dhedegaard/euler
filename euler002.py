#!/usr/bin/python

a = 2
b = 1
sum = 0

while a < 4000000:
    if a % 2 == 0:
        sum += a
    (a, b) = (a + b, a)

print sum
