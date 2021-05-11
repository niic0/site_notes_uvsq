import pandas as pd
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
import random
import sys
import collections

class Vertex:
    def __init__(self, vertex):
        self.name = vertex
        self.neighbors = {}

    """
    Add neighbor to actual vertex
    Add actual vertex to neighbors of neighbor
    """
    def add_neighbor(self, neighbor, weight):
        if isinstance(neighbor, Vertex): # check if neighbor is a Vertex
            if neighbor.name not in self.neighbors and (neighbor.name != self.name): # if neighbord to add is not already in neighbors list
                self.neighbors[neighbor.name] = weight
                neighbor.neighbors[self.name] = weight
        else :
            return false

class Graph:
    def __init__(self):
        self.vertices = {}

    def add_vertex(self, vertex):
        if isinstance(vertex, Vertex):
            self.vertices[vertex.name] = vertex.neighbors
        else:
            return false

    def remove_vertex(self, vertexToRemove):
        self.vertices.pop(vertexToRemove)
        for vertexNeighbor in self.vertices.keys():
            if vertexToRemove in self.vertices.get(vertexNeighbor):
                 self.vertices.get(vertexNeighbor).pop(vertexToRemove)

    def remove_edge(self, vertexA, vertexB):
        i = 0
        # if there is one element in vertex
        if len(self.vertices.get(vertexA)) == 1:
            self.vertices.pop(vertexA)
        else:
            self.vertices[vertexA].pop(vertexB)

        if len(self.vertices.get(vertexB)) == 1:
            self.vertices.pop(vertexB)
        else:
            self.vertices[vertexB].pop(vertexA)

    """
    Add adge between two vertex name
    Vertex is created and his neighbor is set properly
    """
    def add_edge(self, vertex1_name, vertex2_name, weight):
        self.vertices[vertex1_name].update({vertex2_name: weight})
        self.vertices[vertex2_name].update({vertex1_name: weight})

    """
    param: tier (a String) is the tier chosen (T1, T2 or T3)
    return: Return the name (in String) of a vertex chosen randomly
    """
    def pick_random_vertex(self, tier):
        list_tier = []

        for vertex in self.vertices:
            if tier in vertex:
                list_tier.append(vertex)

        vertex_name = random.choice(list_tier)
        return vertex_name

    """
    Count the number of edge of vertex in specific tier
    param: <vertex>
    """
    def count_tier(self, vertex, tier):
        count = 0
        for k in self.vertices[vertex]: # For each neighbor of vertex
            if tier in k:
                count+=1

        return count

    """
    Check if the vertex took randomly is not the same has the vertex to asign,
          if the vertex took randomly has not already <neighbor_count> neighbor(s) of <tierToCheck>,
          if the vertex took randomly is not already in the vertex
    """
    def check_vertex_tier(self, vertex_name, rand_vertex, tierToCheck, neighbor_count):
        equal = vertex_name == rand_vertex  # Check if vertex are equal
        neighbor_tier_count = self.count_tier(rand_vertex,tierToCheck) >= neighbor_count   # Count how many tier are already connected to the neighbor
        inVertex = False  # Check if the vertex took randomly is not already the neighbor of the actual vertex

        if rand_vertex in self.vertices[vertex_name]:
            inVertex = True

        if equal or neighbor_tier_count or inVertex:
            return True
        else:
            return False

    """
    Simple recursive Depth first search
    """
    def dfs(self, visited, vertex):
        if vertex not in visited:
            #print(vertex)
            visited.add(vertex)
            for neighbor in self.vertices[vertex]:
                self.dfs(visited, neighbor)
            return visited

    """
    Return true if the graph is connected, false if not
    """
    def check_connected(self):
        spanning_tree = set()
        spanning_tree = self.dfs(spanning_tree, 'T1_1')

        for vertex in self.vertices:
            if vertex not in spanning_tree:
                return False

        return True

    """
    Simple implementation of Dijkstra algorithm
    """
    def dijkstra(self, start):
        shortest_distance = {}
        predecessor = {}
        unseenVertices = self.vertices.copy()
        infinity = 99999

        for vertex in unseenVertices:
            shortest_distance[vertex] = infinity
        shortest_distance[start] = 0

        while unseenVertices:
            minVertex = None
            for vertex in unseenVertices:
                if minVertex is None:
                    minVertex = vertex
                elif shortest_distance[vertex] < shortest_distance[minVertex]:
                    minVertex = vertex
            for childVertex, weight in self.vertices[minVertex].items():
                if weight + shortest_distance[minVertex] < shortest_distance[childVertex]:
                    shortest_distance[childVertex] = weight + shortest_distance[minVertex]
                    predecessor[childVertex] = minVertex
            unseenVertices.pop(minVertex)
        # print(shortest_distance)

        return predecessor, shortest_distance


    """
    Just a simple way to display the graph graphically - not essential
    useless on big graph
    """
    def display(self):
        FROM = []
        TO = []

        for vertex in self.vertices:

            for vertexNeighbor in self.vertices[vertex]:
                FROM.append(vertex)
                TO.append(vertexNeighbor)

        df = pd.DataFrame({ 'from': FROM, 'to': TO})
        G=nx.from_pandas_edgelist(df, 'from', 'to')
        nx.draw(G, with_labels=True, node_size=1000, node_color="skyblue", pos=nx.fruchterman_reingold_layout(G))
        plt.show()


    """
    print in terminal the current graph, node by node 
    with the number of connexion current node has
    """
    def print(self):
        for vertex in self.vertices:
            print("")
            print(vertex + " T1:" + str(self.count_tier(vertex,'T1')) +  " /T2: " + str(self.count_tier(vertex,'T2')) + " /T3:" + str(self.count_tier(vertex,'T3')))
            print(self.vertices.get(vertex))
