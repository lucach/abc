#!/usr/bin/env python

from limiti import *
from graph import *
from varie import *
from numpy.random import seed, randint, shuffle, random
from sys import argv

usage="""Generatore di "latenza".
Parametri:
* N (num nodi)
* W (max peso)
* L (in linea)
* S (seed)
Constraint:
* 3 <= N <= %d
* 1 <= W <= %d
* 0 <= L <= 1
""" % (MAXN, MAXW)


def run(N, W, L):
    type = 'path' if L == 1 else 'tree'
    g = ugraph(N, type=type, w=lambda: randint(1, W))
    g.connect()

    print N
    print g.printedges()


if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, W, L, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)

    assert (3 <= N <= MAXN)
    assert (1 <= W <= MAXW)
    assert (0 <= L <= 1)

    seed(S)
    run(N, W, L)

