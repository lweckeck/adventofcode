import sys

i = open(sys.argv[1]).read()

x, y = (0, 0)
s = set([(x, y)])
for c in i:
    if c == "^":
        y += 1
    elif c == "v":
        y -= 1
    elif c == "<":
        x -= 1
    elif c == ">":
        x += 1
    s.add((x, y))

print len(s)
