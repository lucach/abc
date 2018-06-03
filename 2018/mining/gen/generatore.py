#!/usr/bin/env python

from limiti import *
from sys import argv, exit
from random import sample, shuffle, seed, randint, uniform

usage="""Generatore di "mining".

Parametri:
* N (numero di criptovalute)
* M (minuti entro cui completare il mining, -1 speciale: sempre possiibile con 1 GPU)
* S (seed)

Costraint: 
* 1 <= N <= %d
* 1 <= M <= %d
""" % (MAXN, MAXM)


def run(N, M):
    if M == -1:
        values = [randint(1, 100) for _ in xrange(N)]
        print N, sum(values) + randint(1, 1000)
    else:
        values = [randint(1, M / 2) for _ in xrange(N)]
        print N, M
    for v in values:
        print v,

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])

    assert(1 <= N <= MAXN)
    if M != -1: 
        assert(1 <= M <= MAXM)
        assert(M >= N)
    seed(S)
    run(N, M)
