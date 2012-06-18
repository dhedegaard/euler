#!/usr/bin/python

def sum_of_square(cap):
    sum = 0
    for i in xrange(1, cap + 1):
        sum += i ** 2
    return sum

def square_of_sum(cap):
    sum = 0
    for i in xrange(1, cap + 1):
        sum += i
    sum **= 2
    return sum

cap = 100
sum_square = sum_of_square(cap)
square_sum = square_of_sum(cap)
diff = square_sum - sum_square
print "%d - %d = %d" % (square_sum, sum_square, diff)
