#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)

def run(f, st):
    assert(len(f) >= 2)
    prima = map(int, f[0].split())
    assert(len(prima) == 2)
    N, M = prima
    assert(len(f) == 1 + M)
    assert(2 <= N <= MAXN)
    assert(1 <= M <= MAXM)

    adjlist = {}
    seen = set()

    for i in xrange(M):
        riga = map(int, f[i+1].split())
        assert(len(riga) == 2)
        da, a = riga
        assert(1 <= da <= N)
        assert(1 <= a <= N)
        assert(da != a)

        seen.add(da)
        seen.add(a)
        
        if da not in adjlist:
            adjlist[da] = set()
        adjlist[da].add(a)

        if a not in adjlist:
            adjlist[a] = set()
        adjlist[a].add(da)

    # Verifico l'assenza di archi ripetuti
    assert(sum(map(len, adjlist.itervalues())) == 2*M)

    # Verifico che non ci siano nodi isolati (senza archi incidenti)
    assert(len(seen) == N)

    return 0


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    f = open(sys.argv[1]).readlines()
    st = int(sys.argv[2])
    exit(run(f, st))
