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
    N, M = map(int, f[0].split())
    assert(1 <= N <= MAXN)
    assert(1 <= M <= MAXM)
    values = map(int, f[1].split())
    assert(len(values) == N)
    assert(all(1 <= v <= MAXV for v in values))
    return 0


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    st = int(sys.argv[2])
    exit(run(f, st))
