#!/usr/bin/env python3

import sys

n_depts = int (sys.stdin.readline ())

lst = []
i = 0
for i in range (n_depts):
    dept = sys.stdin.readline ().rstrip ('\n')
    for line in sys.stdin:
        line = line.strip ('\n')
        if line == "":
            break
        
        i += 1
        pers = line.split (',')
        lst.append ([pers[2], i, dept, pers])

lst.sort ()
for p in lst:
    print (40 * '-')
    pers = p[3]
    print (pers[0], pers[1], pers[2])
    print (pers[3])
    print ("Department:", p[2])
    print ("Home Phone:", pers[4])
    print ("Work Phone:", pers[5])
    print ("Campus Box:", pers[6])
