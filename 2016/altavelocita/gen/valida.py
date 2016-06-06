#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def run(f):
    N, K = map(int, f[0].split())
    assert(len(f) == N + 1)
    assert( 1 <= N <= MAXN)

    first = []
    last = []

    count = 0

    for r in f[1:]:
        riga = map(int, r.split())
        assert (len(riga) == 2)
        assert (0 <= riga[0] < MAXK)
        assert (0 <= riga[1] < MAXK)
        assert (riga[0] <= riga[1])
        first += [riga[0]]
        last += [riga[1]]
        count += riga[1] - riga[0] + 1

    assert(K >= 1 and K <= count)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    exit(run(f))
