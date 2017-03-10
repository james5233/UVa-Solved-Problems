#!/usr/bin/env python3
import sys
import itertools

s = sys.stdin.readline ()
while len (s) > 0:
    #while len (s) == 1:
    #    s = sys.stdin.readline ()

    s = s.rstrip ('\n');
    e = sys.stdin.readline ();
    #while len (e) == 1:
    #    e = sys.stdin.readline ();

    e = e.rstrip ('\n');

    #print ("[" + s + "] [" + e + "]")
    
    len_s = len (s)
    case_res = []

    ch = {}
    ct_s = {}
    i = 0;
    for c in s:
        if c not in ch:
            ch[c] = []
            ct_s[c] = 0

        ch[c].append (i)
        ct_s[c] += 1
        i += 1
    
    ct_e = {}
    for c in e:
        if c not in ct_e:
            ct_e[c] = 0

        ct_e[c] += 1

    if ct_s != ct_e:
        print ("[\n]")
        s = sys.stdin.readline ()
        continue

    arr = []
    q = []
    for w in e:
        arr.append (w)
    
    for w in s:
        q.append (w)

    q.reverse ()
    #print ("q = " + str (q) + " and arr = " + str (arr))
    j = 0
    stn = []
    while j < len_s:
        if len (stn) > 0 and stn[-1] == arr[j]:
            stn.pop ()
            j += 1
        elif len (q) > 0:
            stn.append (q.pop ())
        else:
            break

    if j < len_s:
        print ("[\n]")
        s = sys.stdin.readline ()
        continue
        
    lst = []
    for k in ch:
        lst.append ([list(x) for x in itertools.permutations (ch[k])])

    for elem in itertools.product (*lst):
        dct = {}
        ind = {}
        j = 0
        for k in ch:
            dct[k] = elem[j]
            j += 1
            ind[k] = 0
        
        arr = []
        for w in e:
            arr.append (dct[w][ind[w]])
            ind[w] += 1

        q = list (range (len_s))
        q.reverse ()
        j = 0
        stn = []
        res = []
        while j < len_s:
            if len (stn) > 0 and stn[-1] == arr[j]:
                res.append ('o')
                stn.pop ()
                j += 1
            elif len (q) > 0:
                res.append ('i')
                stn.append (q.pop ())
            else:
                break

        if j >= len_s:
            res_str = " ".join (res)
            case_res.append (res_str)


    case_res.sort ()
    print ("[")
    for sc in case_res:
        print (sc)
    print ("]")
    s = sys.stdin.readline ()
