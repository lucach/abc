#!/usr/bin/env pypy

from limiti import *
from sys import argv, exit, stderr
import os
from itertools import islice
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "paper".

Parametri:
* N (num nodi)
* T (tipo di risposta [0 o 1])
* S (seed)

Constraint:
* 3 <= N <= %d
""" % (MAXN)

def random_chunks(l, N):
    it = iter(l)
    while True:
        nxt = list(islice(it, randint(1, N / 2)))
        if nxt:
            yield nxt
        else:
            break


def run(N, T):

    nodes = [i for i in xrange(1, N + 1)]
    shuffle(nodes)
    components = list(random_chunks(nodes, N))
    edges = []
    for c in components:
        if len(c) > 1:
            # Devo renderla fortemente connessa
            # Per semplicità creo un ciclo tra i nodi 1 -> 2 -> ... -> N -> 1
            for i in xrange(len(c)):
                edges.append((c[i % len(c)], c[(i + 1) % len(c)]))
            # E aggiungo qualche arco a caso
            for i in xrange(N):
                e = sample(c, 2)
                edges.append(tuple(e))
        
    # Unisco le componenti
    # Per semplicità creo una sequenza tra le componenti 1 -> 2 -> ... -> N
    for i in xrange(len(components) - 1):
        edges.append((choice(components[i]), choice(components[i + 1])))
    # E aggiungo qualche arco tra le componenti a caso
    # (ma non in ingresso alla prima!)
    for _ in xrange(2 * len(components)):
        l1 = [i for i in xrange(0, len(components))]
        c1 = sample(l1, 1)[0]
        l2 = [i for i in xrange(1, len(components)) if i != c1]
        c2 = sample(l2, 1)[0]
        e = [choice(components[c1]), choice(components[c2])]
        edges.append(tuple(e))
    # Se T == 0, allora aggiungo anche un arco in ingresso alla prima
    # componente, affinché la risposta sia 0.
    if T == 0:
        edges.append((choice(components[randint(1, len(components) - 1)]), choice(components[0])))

    # Rimuovo eventuali archi non unici
    edges = list(set(edges))
    shuffle(edges)
    print N, len(edges)
    for e in edges:
        print e[0], e[1]


if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, T, S = map(int, argv[1:])

    assert (3 <= N <= MAXN)

    seed(S)
    run(N, T)
