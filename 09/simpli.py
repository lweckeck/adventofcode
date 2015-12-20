import sys

nodes = set()
edges = list()

for line in sys.stdin.readlines():
    u, _, v, _, d = line.split()
    nodes.add(u)
    nodes.add(v)
    edges.append((u, v, d))

nodes = list(nodes)
print "{} {}".format(len(nodes), 2*len(edges))
for u, v, d in edges:
    print "{} {} {}".format(nodes.index(u), nodes.index(v), d)
    print "{} {} {}".format(nodes.index(v), nodes.index(u), d)
