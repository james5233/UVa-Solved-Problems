#!/usr/bin/env python3
import sys

try:
    T = int (sys.stdin.readline ())

    for t in range (T):
        l = sys.stdin.readline ()
        l = l.rstrip ('\n')

        [S, A, F] = [ int (x) for x in l.split () ]
        coord = [[], []]
        try:
            for f in range (F):
                l = sys.stdin.readline ()
                l = l.rstrip ('\n')
                [s, a] = [ int (x) for x in l.split () ]
                coord[0].append (s)
                coord[1].append (a)

            s = [0, 0]
            for i in [0, 1]:
                coord[i].sort ()
                s[i] = coord[i][(F - 1) // 2]

            print ("(Street: " + str (s[0]) + ", Avenue: " + str (s[1]) + ")")
        except:
            pass
except:
    pass
