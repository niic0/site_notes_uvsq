#!/usr/bin/env python
import collections
import sys
from graph import Graph
from graph import Vertex

G = {
    'a':{'b':10, 'c':3},
    'b':{'a':10, 'c':1,'d':2},
    'c':{'b':1, 'a':3, 'd':8,'e':2},
    'd':{'c':8, 'e':7, 'b':2},
    'e':{'c':2, 'd':7}
}

# Création des sommets
buf = Vertex('b')
voisin = Vertex('c')
voisin2 = Vertex('d')
buf.add_neighbor(voisin, 5)
buf.add_neighbor(voisin2, 5)

#création du graphe
graph = Graph()
graph.add_vertex(buf)
graph.add_vertex(voisin)
graph.add_vertex(voisin2)


print("avant add edge")
graph.print()

graph.add_edge('c','d', 8)


print("apres add edge")
graph.print()
