#!/usr/bin/env python

from __future__ import print_function
from limiti import *
from random import sample, seed, randint, shuffle, random
from sys import argv


usage="""Generatore di "verifiche".

Parametri:
* N
* T
* R
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= T <= %d
* 1 <= R <= %d
""" % (MAXN, MAXT, MAXR)


def run(N, T, R):

    print(N, T, R)
    MAXV = 1000 if N == 1 else 2 * N
    values = sample(xrange(1, MAXV), N)
    values.sort()

    print(' '.join(map(str, values)))

if __name__ == "__main__":
    if len(argv) != 5:
        print(usage)
        exit(1)

    N, T, R, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (1 <= T <= MAXT)
    assert (1 <= R <= MAXR)
    seed(S)
    run(N, T, R)

