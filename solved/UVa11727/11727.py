#!/usr/bin/env python3

T = int (input ())

for i in range (T):
    (x, y, z) = [ int (p) for p in input ().split () ]
    
    if y > z:
        y, z = z, y

    if x > y:
        x, y = y, x

    if y > z:
        y, z = z, y
    
    print ("Case", str ( i + 1) + ":", y)

