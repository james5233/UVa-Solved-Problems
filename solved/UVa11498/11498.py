#!/usr/bin/env python3

K = int (input ())

while K > 0:
    (X, Y) = [ int (i) for i in input ().split () ]

    for i in range (K):
        (x, y) = [ int (i) for i in input ().split () ]

        if x == X or y == Y:
            print ("divisa")
        else:
            res = ""
            if y > Y:
                res += "N"
            else:
                res += "S"
            
            if x > X:
                res += "E"
            else:
                res += "O"

            print (res)
        

    K = int (input ())
