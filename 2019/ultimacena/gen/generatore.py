#!/usr/bin/env python2

from limiti import *
from graph import *
from random import choice, sample, seed, randint, shuffle, random
from sys import argv


usage="""Generatore di "ultimacena".

Parametri:
* N (nodi)
* M (archi, -1 o -2 per grafo speciale)
* S (seed)

Constraint:
* 2 <= N <= %d
* 1 <= M <= %d
""" % (MAXN, MAXM)

def get_other_node(N, cover):
    while True:
        v = randint(0, N-1)
        if v not in cover:
            return v

def special_1(N):
    # Genera un grafo particolare, preferenzialmente di 21 nodi, in modo
    # da far fallire l'euristica greedy stupida.
    # Il nodo 0 ha 10 vicini, ciascuno di questi ha un figlio.
    g = ugraph(N)
    nodes = range(N)
    shuffle(nodes)
    for i in range(1, 10+1):
        g.add([nodes[0], nodes[i]])
    if N == 21:
        for i in range(1, 10+1):
            g.add([nodes[i], nodes[i+10]])
    else:  # N = 15
        for i in range(1, 4+1):
            g.add([nodes[i], nodes[i+10]])
        for i in range(5, 9+1):
            g.add([nodes[i], nodes[i+1]])
    return g

def special_2():
    # Genera un grafo particolare di 51 nodi in modo da far fallire l'euristica
    # greedy che si accorge essere conveniente prendere i nodi a cui sono collegati
    # nodi aventi grado 1.
    # Il nodo 0 ha 10 vicini, ciascuno di questi ha quattro figli. Ciascuno di questi
    # quattro figli e' connesso al padre del gruppo "successivo".
    # I padri sono [1, 6, 11, ..., 46]. I figli di 1 sono [2, 3, 4, 5] e sono connessi a 6.
    g = ugraph(51)
    nodes = range(51)
    shuffle(nodes)
    for i in range(1, 46+1, 5):
        g.add([nodes[0], nodes[i]])
        for j in range(1, 5):
            g.add([nodes[i], nodes[i+j]])
            g.add([nodes[i+j], nodes[(i+5)%50]])
    return g

def normal(N, M):
    # Genera un grafo a caso come fosse bipartito: un lato rappresenta la copertura
    # di 10 nodi che vorremmo individuare.
    g = ugraph(N)
    K = 10
    central_nodes = sample(range(N), K)

    for v in range(N):
        if v not in central_nodes:
            nodes = sample(central_nodes, 2)
            g.add([v, nodes[0]])
            g.add([v, nodes[1]])
        else:
            g.add([v, get_other_node(N, central_nodes)])

    # Aggiungo archi a caso con un estremo in central_nodes escluso quello speciale
    while g.M() < M:
        node = central_nodes[randint(0, K-1)]
        g.add([node, get_other_node(N, central_nodes)])

    return g

def run(N, M):
    if M == -1:
        assert(N == 15 or N == 21)
        g = special_1(N)
    elif M == -2:
        g = special_2()
    else:
        g = normal(N, M)
    print g.N(), g.M()
    print g.printedges()

if __name__ == "__main__":
    if len(argv) != 4:
        print(usage)
        exit(1)

    N, M, S = map(int, argv[1:])

    assert (2 <= N <= MAXN or N < 0)
    assert (1 <= M <= MAXM or M < 0)
    seed(S)
    run(N, M)

