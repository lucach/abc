#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def run(f, st):
    N, T, R = map(int, f[0].split())
    assert(len(f) == 2)
    assert( 1 <= N <= MAXN)
    assert( 1 <= T <= MAXT)
    assert( 1 <= R <= MAXR)

    if st == 1:
        assert(N == 1)

    valori = map(int, f[1].split())

    assert(len(valori) == N)

    assert(1 <= valori[0] <= MAXV)
    for i in xrange(2, N):
        assert(1 <= valori[i] <= MAXV)
        assert(valori[i - 1] < valori[i])


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    st = int(sys.argv[2])
    exit(run(f, st))
