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
    assert(len(f) == 1)
    N, K = map(int, f[0].split())
    assert(2 <= N <= MAXN)
    assert(2 <= K <= MAXK)
    return 0


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    st = int(sys.argv[2])
    exit(run(f, st))
