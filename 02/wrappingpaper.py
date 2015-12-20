import sys

f = open(sys.argv[1])

sqft = 0
for line in f.readlines():
    l, w, h = map(int, line.split('x'))
    sides = [l*w, l*h, h*w]
    sqft += (2*sum(sides) + min(sides))

print sqft
