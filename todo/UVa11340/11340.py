#!/usr/bin/env python3

T = int( input())
for t in range (T):
    N = int (input ())
    d = {}
    for i in range (N):
        s = input ();
        d[s[0]] = int (s[1:])
    
    M = int (input ())
    total = 0

    for i in range (M):
        s = input ();
        for c in s:
            if c in d:
                total += d[c]

    print ("%.2f$"%(total/100.0))

