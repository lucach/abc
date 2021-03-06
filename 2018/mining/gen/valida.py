#!/usr/bin/env python

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N, M = map(int, f[0].split())
    assert( 1 <= N <= MAXN )
    assert( 1 <= M <= MAXM )
    assert( len(f) == 2 )
    values = map(int, f[1].split())
    assert( len(values) == N)
    for v in values:
        assert( 1 <= v <= MAXM)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)

