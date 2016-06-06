#!/usr/bin/env python

from limiti import *
from graph import *
from random import sample, seed, randint, shuffle, random
from sys import argv


usage="""Generatore di "edifici".

Parametri:
* N (nodi)
* M (archi)
* K (market)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= M <= %d
* 1 <= K <= %d
""" % (MAXN, MAXM, MAXK)


def run(N, M, K):

    g = ugraph(N, w=lambda: randint(1, MAXW))
    g.connect()
    g.addedges(M - g.M())

    markets = sample(xrange(1, N), K)

    print N, M, K
    print ' '.join(map(str, markets))
    print g.printedges()

if __name__ == "__main__":
    if len(argv) != 5:
        print(usage)
        exit(1)

    N, M, K, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    assert (1 <= K <= MAXK)
    seed(S)
    run(N, M, K)

