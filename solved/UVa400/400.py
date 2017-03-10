#!/usr/bin/env python3

import sys

for line in sys.stdin:
    n = int (line.strip ("\n"))

    flnames = [];
    ct = 0
    for line in sys.stdin:
        flnames.append (line.strip ("\n"))
        ct += 1
        if ct >= n:
            break
    
    l = max ([ len(line) for line in flnames ])
    n_cols = (60 - l)// (l + 2) + 1
    n_rows = (n + n_cols - 1) // n_cols

    flnames.sort ()
    oplst = [ [] for i in range (n_rows) ]

    for i in range (n):
        oplst[i % n_rows].append (flnames[i])

    print (60 * "-")
    #print (oplst)

    for i in range (n_rows):
        s = [ w.ljust (l + 2) for w in oplst[i][:-1] ]
        s +=  oplst[i][-1:]
        opstr = "".join (s)
        print (opstr)

