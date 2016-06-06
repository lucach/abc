#!/usr/bin/env python

from limiti import *
from random import seed, randint, shuffle, random
from sys import argv

usage="""Generatore di "altavelocita".

Parametri:
* N (num intervalli)
* K (MAXK alternativo, -1 per usare MAXK da limiti.py)
* S (seed)

Constraint:
* 1 <= N <= %d
""" % (MAXN)


def run(N, K):

    if K != -1:
        global MAXK
        MAXK = K

    first = []
    last = []
    count = 0
    for i in xrange(N):
        first += [randint(0, MAXK - 1)]
        last += [randint(first[i], MAXK - 1)]
        count += last[i] - first[i] + 1

    K = randint(1, count)

    print N,K
    for i in xrange(N):
        print first[i], last[i]


if __name__ == "__main__":

    if len(argv) != 4:
        print usage
        exit(1)

    N, K, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    seed(S)
    run(N, K)

