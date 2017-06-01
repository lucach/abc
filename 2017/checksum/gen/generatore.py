#!/usr/bin/env python

from limiti import *
from sys import argv, exit
from random import sample, shuffle, seed, randint, uniform

usage="""Generatore di "checksum".

Parametri:
* M (massimo valore dei checksum)
* P (numero di pacchetti)
* S (seed)

Costraint: 
* 1 <= M <= %d
* 1 <= P <= %d
""" % (MAXM, MAXP)


def run(M, P):
    print P, M
    values = []
    printed = [False for _ in xrange(M + 1)]

    # Trovo i numeri primi fino a M
    isprime = [True for _ in xrange(M+1) ]
    isprime[1] = False
    primes = []
    for i in xrange(2, M+1):
        j = i*i
        while j <= M:
            isprime[j] = 0
            j += i
    for i in xrange(2, M + 1):
        if isprime[i]:
            primes.append(i)
            printed[i] = True

    values.extend(primes)

    # E ci aggiungo qualche numero non primo
    for i in xrange(P - len(primes)):
        val = randint(1, M)
        while printed[val]:
            val = randint(1, M)
        values.append(val)
        printed[val] = True

    # Metto un po' di disordine, anche se non fa differenza
    shuffle(values)
    for v in values:
        print v,

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    M, P, S = map(int, argv[1:])

    assert(1 <= M <= MAXM)
    assert(1 <= P <= MAXP)
    seed(S)
    run(M, P)
