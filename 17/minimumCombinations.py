import sys

containers = list()


def combinations(n, c):
    if n == 0:
        return [[]]
    if c == 0:
        return []
    result = combinations(n, c-1)
    if n >= containers[c-1]:
        result += [[containers[c-1]] + s
                   for s in combinations(n-containers[c-1], c-1)]
    return result


def main():
    if len(sys.argv) < 2:
        print "Usage: python minimumCombinations.py <#item> <container-file>"
        sys.exit()
    for line in open(sys.argv[2]).readlines():
        containers.append(int(line))

    n = int(sys.argv[1])
    m = len(containers)

    result = combinations(n, m)

    lengths = map(len, result)
    result_filtered = filter(lambda x: x == min(lengths), lengths)
    print len(result_filtered)


if __name__ == '__main__':
    main()
