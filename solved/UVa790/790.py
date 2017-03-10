#!/usr/bin/env python3

import sys
T = int (sys.stdin.readline ())
sys.stdin.readline ()

for test_case in range (T):
    solved = {}
    for line in sys.stdin:
        line = line.rstrip ('\n')
        
        if line == "":
            break
        
        arr = list (line.split ())
        arr[0] = int (arr[0])
        s = [ int(x) for x in  arr[2].split (':') ]
        arr[2] = s[0]*60 + s[1];

        [ team, prob, tm, status ] = arr

        if team not in solved:
            solved[team] = {}
        
        if prob not in solved[team]:
            solved[team][prob] = []
        
        solved[team][prob].append ((tm, status))

    for t in solved:
        for p in solved[t]:
            solved[t][p].sort ()

    res = {}
    for t in solved:
        res[t] = {}
        for p in solved[t]:
            l = [ s[1] for s in solved[t][p] ]
            if 'Y' in l:
                i = l.index ('Y')
                tm = solved[t][p][i][0] + 20 * i
                res[t][p] = tm
        
    team = list (solved.keys ())
    team.sort ()

    fin = []
    for t in range(1, max(team) + 1):
        if t in res:
            l = res[t].values ()
            fin.append ([len (l), sum (l), t])
        else:
            fin.append ([ 0, 0, t])

    fin.sort (key = lambda x: [-x[0], x[1], x[2]])

    print ("RANK TEAM PRO/SOLVED TIME")
    i = 0
    t_old = [-1, -1]
    i_old = 0
    for t in fin:
        i += 1
        if [ t[0], t[1] ] == t_old:
            r = i_old
        else:
            r = i
            i_old = i

        t_old = [ t[0], t[1] ]

        if t[0] != 0:
            print (str(r).rjust(4), str(t[2]).rjust(4), \
               str(t[0]).rjust(4), str(t[1]).rjust(10))
        else:
            print (str(r).rjust(4), str(t[2]).rjust(4))
    
    if test_case != T - 1:
        print ("")
