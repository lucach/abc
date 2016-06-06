#!/usr/bin/env python

from limiti import *
from random import seed, randint, shuffle, random
from sys import argv

usage="""Generatore di "esame".

Parametri:
* N (num)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N):
    print N
    print " ".join(map(str, [randint(MINV, MAXV) for i in xrange(0, N)]))


if __name__ == "__main__":

    if len(argv) != 3:
        print usage
        exit(1)

    N, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N)

