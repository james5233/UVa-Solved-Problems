#!/usr/bin/env python3

import sys
ignore = {}

for s in sys.stdin:
    s = s.strip ("\n")
    if s == "::":
        break
    ignore[s.lower ()] = 1

# print ("IGNORE: ", ignore, " END")

line_no = 0
arr = []
for line in sys.stdin:
    line_no += 1
    line = line.strip ().lower ()
    words = list (line.split ())
    l = len (words)
    for w in range (l):
        if words[w] not in ignore:
            s = " ".join (words[:w] + [words[w].upper ()] + words[w + 1:])
            arr.append ([words[w], line_no, s])

arr.sort ()

for s in arr:
    print (s[2])

