#!/usr/bin/env python

import sys

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} file out")

with open(sys.argv[1]) as fin:
    with open(sys.argv[2], "wb") as fout:
        s = ""
        i = []
        while True:
            c = fin.read(1)
            if not c:
                break
            if c == '0' or c == '1':
                s += c
            if len(s) == 8:
                i.append(int(s, 2))
                s = ""
            if len(i) == 4:
                b = bytes(i[::-1])
                fout.write(b)
                i = []
if len(s) != 0 or len(i) != 0:
    print(f"Warning: incomplete instruction")
