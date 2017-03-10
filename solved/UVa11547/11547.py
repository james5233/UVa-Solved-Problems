#!/usr/bin/env python3

T = int (input ())

for t in range (T):
    n = int (input ())
    res = (((n * 63 + 7492) * 235) // 47) - 498
    
    if res < 0:
        res *= -1
    
    res = (int (res) % 100) // 10
    print (res)

