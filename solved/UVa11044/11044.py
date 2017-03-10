#!/usr/bin/env python3

T = int (input ());
for t in range (T):
    (n , m) = [ int (x) for x in input ().split () ]
    print ((n // 3) * (m // 3))

