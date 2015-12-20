import sys

containers = list()
cache = list()
cached = list()

def combinationsWithMinContainers(n, c):
    if n == 0:
        return (1, 0)
    if c == 0:
        return (0, 0)
    if cached[n][c]:
        return cache[n][c]
    combinations, cons = combinationsWithMinContainers(n, c-1)
    if (n > containers[c-1]):
        combinations2, cons2 = combinationsWithMinContainers(
            n-containers[c-1], c-1)
        if cons2 < cons:
            combinations = combinations2
            cons = cons2
        elif cons2 == cons:
            combinations += combinations2
            cons += cons2
    cache[n][c] = combinations, cons
    cached[n][c] = True
    return combinations, cons

def main():
    if len(sys.argv) < 2:
        print "Usage: python minimumCombinations.py <#item> <container-file>"
        sys.exit()
    for line in open(sys.argv[2]).readlines():
        containers.append(int(line))

    n = int(sys.argv[1])
    m = len(containers)

    global cache, cached
    cache = [[None for _ in range(m+1)] for _ in range(n+1)]
    cached = [[False for _ in range(m+1)] for _ in range(n+1)]

    print combinationsWithMinContainers(n, m)
    

if __name__ == '__main__':
    main()
