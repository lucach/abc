#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def isUnique(x):
    seen = set()
    return not any(i in seen or seen.add(i) for i in x)

def run(f):
    assert(len(f) == 2)
    prima = map(int, f[0].split())
    assert(len(prima) == 1)
    N = prima[0]
    assert(2 <= N <= MAXN)
    seconda = map(int, f[1].split())
    assert(isUnique(seconda))
    for v in seconda:
        assert (1 <= v <= MAXV)



if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    exit(run(f))
