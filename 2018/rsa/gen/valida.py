#!/usr/bin/env pypy

from limiti import *

import string
import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def run(f, st):
    assert(len(f) == 2)
    prima = map(int, f[0].split())
    assert(len(prima) == 3)
    N, d, L = prima
    assert(MINN <= N <= MAXN)
#    assert(1 <= d < N)
    assert(1 <= L <= MAXL)
    messaggio = map(int, f[1].split())
    assert(1 <= len(messaggio) <= 100)

    return 0


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    st = int(sys.argv[2])
    exit(run(f, st))
