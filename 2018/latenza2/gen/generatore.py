#!/usr/bin/env python

from limiti import *
from graph import *
from random import sample, seed, randint, shuffle, random
from sys import argv


usage="""Generatore di "latenza2".

Parametri:
* N (nodi)
* M (archi)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= M <= %d
""" % (MAXN, MAXM)


def run(N, M):
    if M == -1:
        g = ugraph(N, type='path', w=lambda: randint(1, MAXW))
        g.connect()
    else:
        g = ugraph(N, w=lambda: randint(1, MAXW))
        g.connect()
        if g.M() != M:
            g.addedges(M - g.M())

    print g.N(), g.M()
    print g.printedges()

if __name__ == "__main__":
    if len(argv) != 4:
        print(usage)
        exit(1)

    N, M, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (1 <= M <= MAXM or M == -1)
    seed(S)
    run(N, M)

