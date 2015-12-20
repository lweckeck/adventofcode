import sys

def permutations(l):
    if len(l) <= 1:
        yield l
    else:
        head = l[0]
        tail = l[1:]
        for p in permutations(tail):
            for i in range(len(p)):
                yield p[:i] + [head] + p[i:]
            yield p + [head]

def main():
    d = dict()
    for line in sys.stdin.readlines():
        tokens = line.split()
        p1 = tokens[0]
        p2 = tokens[10].replace('.', '')

        v = int(tokens[3])
        if p1 not in d:
            d[p1] = dict()
        if tokens[2] == "gain":
            d[p1][p2] = v
        elif tokens[2] == "lose":
            d[p1][p2] = -v
        else:
            raise ValueError("Expexted gain or lose at pos 2!")
    for key in d:
        d[key]['Lennart'] = 0
    d['Lennart'] = {key: 0 for key in d}

    hs = list()
    for a in permutations(d.keys()):
        h = 0
        for i in range(len(a) - 1):
            h += d[a[i]][a[i+1]] + d[a[i+1]][a[i]]
        h += d[a[0]][a[len(a)-1]] + d[a[len(a)-1]][a[0]]
        hs.append(h)
    print len(hs)
    print max(hs)

if __name__ == "__main__":
    main()
