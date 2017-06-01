#!/usr/bin/env python

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    N = int(f[0])
    assert( 1 <= N <= MAXN )
    assert( len(f) == 3 )

    values_A = map(int, f[1].split())
    assert( len(values_A) == N )
    for v in values_A:
        assert (1 <= v <= MAXV)

    values_B = map(int, f[2].split())
    assert( len(values_B) == N )
    for v in values_B:
        assert (1 <= v <= MAXV)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)

