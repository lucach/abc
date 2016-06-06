#!/usr/bin/env python

from limiti import *
from varie import *
from numpy.random import seed, randint, shuffle, random
from sys import argv

usage="""Generatore di "interrogazioni".
Parametri:
* N (num studenti)
* V (max valore)
* S (seed)
Constraint:
* 2 <= N <= %d
* N <= V <= %d
""" % (MAXN, MAXV)


def run(N, V):
    values = list(range(1, V + 1))
    shuffle(values)
    values = values[:N]
    print N
    for v in values:
        print v,


if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, V, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)

    assert (2 <= N <= MAXN)
    assert (N <= V <= MAXV)

    seed(S)
    run(N, V)

