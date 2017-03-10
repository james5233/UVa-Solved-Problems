#!/usr/bin/env python3

case_num = 0
N = int (input ())
while N > 0:
    arr = [ int (i) for i in input ().split () ]
    
    req = 0
    given = 0
    case_num += 1

    for val in arr:
        if val == 0:
            given += 1
        else:
            req += 1
    
    print ("Case %d: %d" % (case_num, req - given))

    N = int (input ())

