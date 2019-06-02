#!/usr/bin/env python2

from limiti import *
from random import sample, seed, randint, shuffle, random
from sys import argv
import time

usage="""Generatore di "quadri".

Parametri:
* N (numero di quadri)
* T (tipo di risposta: 0 risposta sempre zero, 1 risposta sempre N, 2 casuale, 3 primo valore alto)
* S (seed)
"""

def run(N, T):
    ans = randint(1, N-1)
    if T == 0:
        MINV = 2
    else:
        MINV = 1

    if T == 3:
        values = [MAXV] + [1 for _ in range(N-1)]
    else:
        values = [randint(MINV, MAXV) for _ in range(N)]
    
    M = 0
    cursum = 0
    for i in range(N):
        cursum += values[i]
        if i >= ans:
            cursum -= values[i-ans]
        M = max(M, cursum)

    if T == 0:
        M = randint(1, min(values)-1)
    elif T == 1:
        M = randint(sum(values)+1, MAXM)
    elif T == 3:
        M = MAXV-1

    print N, M
    for i in range(N):
        print values[i],
    print

if __name__ == "__main__":
    if len(argv) != 4:
        print(usage)
        exit(1)

    N, T, S = map(int, argv[1:])

    assert (1 <= N <= MAXN)
    assert (T == 0 or T == 1 or T == 2 or T == 3)
    seed(S)
    run(N, T)

