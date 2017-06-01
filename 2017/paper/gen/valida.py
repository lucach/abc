#!/usr/bin/env pypy

from limiti import *

from sys import argv, exit, stderr
import os

def usage():
    print >> stderr, "Usage: %s file_input.txt" % \
        os.path.basename(argv[0])
    exit(1)

def run(f):
    assert(len(f) >= 2)
    prima = map(int, f[0].split())
    assert(len(prima) == 2)
    N, M = prima
    assert(len(f) == M+1)
    assert(3 <= N <= MAXN)
    edges = []
    for i in xrange(M):
        riga = map(int, f[i+1].split())
        assert(len(riga) == 2)
        a, b = riga
        assert(1 <= a <= MAXN)
        assert(1 <= b <= MAXN)
        assert(a != b)
        # Sugli input piccoli controlliamo anche l'unicità degli archi
        if N < 1000:
            assert([a, b] not in edges)
            edges.append([a, b])
    return 0 # Input corretto

if __name__ == "__main__":
    if len(argv) < 2:
        usage()

    f = open(argv[1]).readlines()
    exit(run(f))
