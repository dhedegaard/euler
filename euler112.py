#!/usr/bin/python

def is_bouncy(num):
    up = False
    down = False
    prev = -1
    for c in str(num):
        digit = int(c)
        if prev > -1:
            if prev < digit:
                up = True
            elif prev > digit:
                down = True
        if up and down:
            return True
        prev = digit
    return False

if __name__ == "__main__":
    assert not is_bouncy(1223)
    assert not is_bouncy(3221)
    assert is_bouncy(312)
    assert is_bouncy(132)
    bouncy = 0
    non_bouncy = 99
    import numpy
    num = numpy.NAN
    hit50 = False
    hit90 = False
    for i in xrange(100, 1000000000 + 1):
        num = i
        if is_bouncy(i):
            bouncy += 1
        else:
            non_bouncy += 1
        if not hit50 and non_bouncy == bouncy:
            print "50/50 at %s" % num
            hit50 = True
        elif not hit90 and (non_bouncy * 9) == bouncy:
            print "90/10 at %s" % num
            hit90 = True
        elif (non_bouncy * 99) == bouncy:
            print "99/1 at %s" % num
            break
