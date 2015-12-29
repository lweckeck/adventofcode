import sys

containers = list()
cache = list()
cached = list()


def combinations(n, c):
    if n == 0:
        return 1
    if c == 0:
        return 0
    if cached[n][c]:
        return cache[n][c]
    result = combinations(n, c-1)
    if (n >= containers[c-1]):
        result += combinations(n-containers[c-1], c-1)
    cache[n][c] = result
    cached[n][c] = True
    return result


def main():
    if len(sys.argv) < 2:
        print "Usage: python minimumCombinations.py <#item> <container-file>"
        sys.exit()
    for line in open(sys.argv[2]).readlines():
        containers.append(int(line))

    n = int(sys.argv[1])
    m = len(containers)
    print n
    print m

    global cache, cached
    cache = [[None for _ in range(m+1)] for _ in range(n+1)]
    cached = [[False for _ in range(m+1)] for _ in range(n+1)]

    print combinations(n, m)


if __name__ == '__main__':
    main()
