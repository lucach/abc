#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f):
    assert(len(f) >= 2)
    prima = map(int, f[0].split())
    assert(len(prima) == 1)
    N = prima[0]
    assert(len(f) == N)
    assert(3 <= N <= MAXN)
    for i in xrange(N - 1):
        riga = map(int, f[i+1].split())
        assert(len(riga) == 3)
        a, b, c = riga
        assert(1 <= a <= MAXN)
        assert(1 <= b <= MAXN)
        assert(1 <= c <= MAXW)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    exit(run(f))
