#!/usr/bin/env python

from limiti import *
from varie import *
from numpy.random import seed, randint, shuffle, multinomial, random
from sys import argv

usage="""Generatore di "qquadrati".
Parametri:
* N (numero totale di numeri)
* S (seed)

Constraint:
* 2 <= N <= %d
""" % (MAXN)

def run(N):
    valori = randint(1, MAXV, N).tolist()
    print N
    for v in valori:
        print v,


if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)
    assert (1 <= N <= MAXN)
    seed(S)

    run(N)
