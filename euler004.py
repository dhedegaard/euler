#!/usr/bin/python

def is_palindrome(num):
    s = str(num)
    for i in xrange(len(s) / 2):
        if s[i] != s[(i * -1) - 1]:
            return False
    return True

c_max = None
a_max = None
b_max = None

for a in xrange(100, 1000):
    for b in xrange(100, a + 1):
        c = a * b
        if is_palindrome(c):
            if c > c_max:
                c_max = c
                a_max = a
                b_max = b

print "%d * %d = %d" % (a_max, b_max, c_max)
