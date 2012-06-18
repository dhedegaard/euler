#!/usr/bin/python

done = False
for c in range(1, 1001):
    for b in range(1, c):
        for a in range(1, b):
            if a + b + c == 1000 and a ** 2 + b ** 2 == c ** 2:
                print "%d, %d, %d, %d" % (a, b, c, a * b * c)
                done = True
        if done:
            break
    if done:
        break
                
