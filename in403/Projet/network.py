import random
from graph import Graph
from graph import Vertex


def main():
    G = Graph()
    G = createTier(G)
    
    if G.check_connected():
        print("Graph is not connected - aborting")
        exit()
        
    print("\n[USAGE] :\nT1_i  0 < i <= 10\n"
          "T2_k  0 < k <= 20\n"
          "T3_n  0 < n <= 70\n")

    vertexA = input("Enter vertex A : ")
    vertexB = input("Enter vertex B : ")

    if vertexA not in G.vertices or vertexB not in G.vertices:
        print("\nINPUT  WARNING : Vertex not in graph, correct  input:\nT1_1 ... T1_10\nT2_1 ... T2_20\nT3_1 ... T3_70")
        exit()

    # G.print()
 
    predecessor, shortest_distance = G.dijkstra(vertexA)
    path = shortest_path(predecessor, shortest_distance, vertexA, vertexB)

    print_tables(predecessor, shortest_distance, G, all)

    if shortest_distance[vertexB] != 99999:
        print('\nShortest distance is ' + str(shortest_distance[vertexB]))
        print('And the path is ' + str(path))
    

"""
Create backbone
"""
def createTier1(G):
    for i in range(1, 11):
        buf = Vertex('T1_'+str(i))
        G.add_vertex(buf)

    tmp_vertices = G.vertices.copy()

    for vertex in G.vertices:
        for vertexNeighbor in tmp_vertices:
            if random.randrange(100) < 75 and vertex != vertexNeighbor:
                G.add_edge(vertex, vertexNeighbor, random.randrange(5, 11))
        tmp_vertices.pop(vertex)  # Remove vertex that has already been treated

    return G


"""
Create transit nodes
"""
def createTier2(G):
    verticesT2 = []  # To only take vertices 'T2' in the gaph and not all vertices
    for i in range(1, 21):
        buf = Vertex('T2_'+str(i))
        G.add_vertex(buf)
        verticesT2.append(buf.name)

    for vertexT2 in verticesT2:  # loop on all 'T2'
        for i in range(0, random.randrange(1, 3)):
            G.add_edge(vertexT2, G.pick_random_vertex(
                'T1'), random.randrange(10, 21))

    for vertex in verticesT2:
        randValue = random.randrange(2, 4)
        for y in range(0, randValue):
            # check if the actual vertex hasn't been treated yet
            if G.count_tier(vertex, 'T2') < 3 and randValue != G.count_tier(vertex, 'T2'):
                rand_vertex = G.pick_random_vertex('T2')

                while G.check_vertex_tier(vertex, rand_vertex, 'T2', 3):
                    rand_vertex = G.pick_random_vertex('T2')

                G.add_edge(vertex, rand_vertex, random.randrange(10, 21))
    return G


"""
Create nodes of tier 3
"""
def createTier3(G):
    verticesT3 = []
    for i in range(1, 71):
        buf = Vertex('T3_'+str(i))
        G.add_vertex(buf)
        verticesT3.append(buf.name)

    for vertex in verticesT3:
        for i in range(2):
            G.add_edge(vertex, G.pick_random_vertex(
                'T2'), random.randrange(15, 50))

        if G.count_tier(vertex, 'T3') < 1:
            rand_vertex = G.pick_random_vertex('T3')
            while G.check_vertex_tier(vertex, rand_vertex, 'T3', 1):
                rand_vertex = G.pick_random_vertex('T3')
            G.add_edge(vertex, rand_vertex, random.randrange(15, 50))

    return G


"""
Create all tiers
"""


def createTier(G):
    G = createTier1(G)
    print("Tier 1 created")
    G = createTier2(G)
    print("Tier 2 created")
    G = createTier3(G)
    print("Tier 3 created")
    return G


"""
Find the shortest path, based on what Dijkstra found for predecessors and the
shortest distance
"""
def shortest_path(predecessor, shortest_distance, start, end):
    path = []
    currentVertex = end
    while currentVertex != start:
        try:
            path.insert(0, currentVertex)
            currentVertex = predecessor[currentVertex]
        except KeyError:
            break
    path.insert(0, start)
    return path


"""
print the routing table of aked tier
"""
def print_tables(predecessor, shortest_distance, G, tier):
    for vertex in G.vertices:
        print("\n| // ", vertex, " //")
        for destination in G.vertices:
            if destination != vertex:
                path = shortest_path(
                    predecessor, shortest_distance, vertex, destination)
                print("|", destination)
                print("|", path)


if __name__ == "__main__":
    main()
