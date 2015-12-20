import sys

f = open(sys.argv[1])
vowels = {'a', 'e', 'i', 'o', 'u'}
forbidden = {('a', 'b'), ('c', 'd'), ('p', 'q'), ('x', 'y')}
count = 0

for w in f.readlines():
    vowelcount = 0
    hasdouble = False
    hasforbidden = False

    last = ''
    for c in w:
        if (last, c) in forbidden:
            hasforbidden = True
            continue
        if last == c:
            hasdouble = True
        if c in vowels:
            vowelcount += 1
        last = c
    if vowelcount >= 3 and hasdouble and not hasforbidden:
        count += 1
print count
