#!/usr/bin/env python3

s = input ()
while len (s) > 0:
    a = [ int (x) for x in s.split() ]
    b = [ abs (x - y) for x, y in zip (a, a[1:]) ]

    b.sort ()
    print ("b =", b)
    if list(range (1, len(b) + 1)) == b:
        print ("Jolly")
    else:
        print ("Not Jolly")

    s = input ()
