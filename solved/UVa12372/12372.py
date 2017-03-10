#!/usr/bin/env python3

T = int (input ())
for t in range (T):
    arr = [ int (i) <= 20 for i in input ().split () ]
    if arr == 3 * [ True ]:
        print ("Case %d: good"%(t + 1) )
    else:
        print ("Case %d: bad"%(t + 1) )

