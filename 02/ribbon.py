import sys

f = open(sys.argv[1])

r = 0
for l in f.readlines():
    vals = map(int, l.split("x"))
    vals.sort()
    x, y, z = vals
    r += 2*x + 2*y + x*y*z

print r
