#!/usr/bin/env python3
import sys

T = int (sys.stdin.readline ())

for t in range (T):
    arr = []
    num = int (sys.stdin.readline ())
    while num != 0:
        arr.append (num)
        num = int (sys.stdin.readline ())

    arr.sort (reverse = True)
    total = 0
    l = len (arr)
    i = 0

    while i < l and total < 5000000:
        total += 2 * (arr[i] ** (i + 1))
        i += 1

    if total < 5000000:
        print (total)
    else:
        print ("Too expensive")

