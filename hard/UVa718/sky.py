#!/usr/bin/env python3

from queue import *

def gcd(a, b):
    while b != 0:
        r = a % b;
        a = b
        b = r
    return a

def gcd_ex (a, b):
    A = [1, 0, a]
    B = [0, 1, b]

    while B[2] != 0:
        Q = A[2]//B[2]
        T = [ A[i] - Q*B[i] for i in range (3) ]
        A = B
        B = T
    
    return A

def diophantine (a, b, c):
    res = gcd_ex (a, b)
    if c % res[2] == 0:
        return (True, res[0], res[1])
    else:
        return (False, 0, 0)


def find_eq_pt (EQ1, EQ2):
    (B, A) = EQ1
    (D, C) = EQ2

    if A > C:
        C, A = A, C
        B, D = D, B
    
    a = B
    b = D
    c = C - A

    [x, y, d] = gcd_ex (a, b)
    if c % d != 0:
        return (False, 0)
    
    #print "x = ", x, "\ny = ", y, "\nd = ", d

    y = -y;
    a_pr = a / d
    b_pr = b / d

    x_pos = max (0, -x);
    y_pos = max (0, -y);

    n = max ((x_pos + b_pr - 1)//b_pr, (y_pos + a_pr - 1)//a_pr)
    
    #print "n = ", n
    
    if n >= 0:
        return (True, A + B * (x + n * b_pr))
    else:
        return (False, 0)


def is_reacheable_by_elevator (EQ, f):
    (b, a) = EQ

    if b == 0:
        return a == f

    n = (f - a)//b
    if n >= 0 and a + n*b == f:
        return True
    else:
        return False

def connected_elevators (EQ1, EQ2, f):
    (status, n) = find_eq_pt (EQ1, EQ2)
    if status == True and n < f:
        return True
    else:
        return False

# EQ = [ (3, 2), (4, 7), (13, 6), (10, 0) ]
# pt = [ 0, 6 ]
#
# for p in pt:
#    for e in EQ:
#        if is_reacheable_by_elevator (e, p):
#            print "Floor ", p, " is reacheable by Elevator ", e


def floors_reacheable ():
    (F, E, A, B) = list(map(int, input().split(" ")))
    
    elev_list = []
    for e in range(E):
        eqn = list (map(int, input().split(" ")))
        elev_list.append ((eqn))

    if A == B:
        return True

    elev_list = tuple (elev_list)
    
    hit_list = {}
    for elev_ind in range (E):
        e = elev_list[elev_ind]
        if is_reacheable_by_elevator (e, B):
            hit_list[elev_ind] = 1
    
    for elev_ind in range (E):
        e = elev_list [elev_ind]
        if is_reacheable_by_elevator (e, A):
            Q = Queue()
            visited = [ False for i in range (E) ]

            Q.put (elev_ind)
            visited [elev_ind] = True
            while not Q.empty ():
                ind = Q.get ()
                eqn = elev_list[ind]

                if ind in hit_list:
                    return True
                
                for i in range (E):
                    if not visited[i]:
                        if connected_elevators (elev_list[i], eqn, F):
                            if i in hit_list:
                                return True

                            Q.put (i)
                            visited[i] = True
            
            return False
    
    return False


T = int (input ())
for t in range (T):
    if floors_reacheable ():
        print ("It is possible to move the furniture.")
    else:
        print ("The furniture cannot be moved.")
