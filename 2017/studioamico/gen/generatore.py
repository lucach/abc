#!/usr/bin/env pypy

import string

from limiti import *
from sys import argv, exit
from random import choice, sample, shuffle, seed, randint, uniform

usage="""Generatore di "studioamico".

Parametri:
* N (numero elementi)
* S (seed)

Costraint: 
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    print N
    prob = uniform(0, 1)
    if prob < 0.5:
        # In meta' dei casi generiamo completamente a caso
        for _ in xrange(N):
            print randint(0, MAXV - 1) + 1,
        print
        for _ in xrange(N):
            print randint(0, MAXV - 1) + 1,
        print
    else:
        # Vogliamo che ci sia una soluzione.
        # Genero la prima meta' a caso (escludendo pero' il 9, altrimenti sono fregato!)
        first_half = [randint(0, MAXV - 2) for _ in xrange(N)]
        # E la seconda in modo che ogni cifra sia maggiore di quella nella prima meta'
        values = []
        for i in xrange(N):
            values.append(randint(first_half[i] + 1, MAXV - 1))
        shuffle(values)
        for v in first_half:
            print (v + 1),
        print
        for v in values:
            print (v + 1),
        print


if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert(1 <= N <= MAXN)
    seed(S)
    run(N)

