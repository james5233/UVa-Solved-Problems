#!/usr/bin/env python3
import sys

N = int (sys.stdin.readline ())

gene = {}
pars = {}
for n in range (N):
    s = sys.stdin.readline ()
    s = s.strip ('\n')
    arr = list (s.split (' '))

    if arr[1] in ('dominant', 'recessive', 'non-existent'):
        gene[arr[0]] = arr[1]
    elif arr[1] in pars:
        pars[arr[1]].append (arr[0])
    else:
        pars[arr[1]] = [arr[0]]

mp = {}
mp['dd'] = 'dominant'
mp['dn'] = 'recessive'
mp['dr'] = 'dominant'
mp['nn'] = 'non-existent'
mp['nr'] = 'non-existent'
mp['rr'] = 'recessive'

#print ("gene = ", gene)
while len (pars.keys ()) > 0:
    #print ("pars = ", pars)
    lst = {}
    for chld in pars:
        if (pars[chld][0] in gene) and (pars[chld][1] in gene):
            l = list (sorted ([gene[x] for x in pars[chld]]))
            l = l[0][0] + l[1][0]
            #print ("child = ", chld, "Parents = ", pars[chld], "l = ", l)
            gene[chld] = mp[l]
        else:
            lst[chld] = pars[chld]

    pars = lst

for p in sorted (gene.keys ()):
    print (p, gene[p])

