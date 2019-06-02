#!/usr/bin/env python

from limiti import *
from random import sample, seed, randint, shuffle, random
from sys import argv
import time

usage="""Generatore di "progetti".

Parametri:
* N (max number of projects)
* K (max number of projects in a day)
* S (seed)
"""

def run(N, K):
    print("{} {}".format(randint(max(2, N / 10), N), K))

if __name__ == "__main__":
    if len(argv) != 4:
        print(usage)
        exit(1)

    N, K, S = map(int, argv[1:])

    assert (2 <= N <= MAXN)
    assert (2 <= K <= MAXK)
    seed(S)
    run(N, K)

