#!/usr/bin/python

CAP = 100

sum_square = sum([e**2 for e in xrange(1, CAP+1)])
square_sum = sum(xrange(1, CAP+1))**2

print max(sum_square, square_sum) - min(sum_square, square_sum)
