import sys

value = dict()


def eval(s):
    if s.isdigit():
        return int(s)
    print "eval {} = {}".format(s, value[s])
    tokens = value[s].split()
    if len(tokens) == 1:
        r = eval(tokens[0])
    elif (tokens[0] == "NOT"):
        x = eval(tokens[1])
        r = ~x & 255
    else:
        x = eval(tokens[0])
        y = eval(tokens[2])
        if (tokens[1] == "AND"):
            r = x & y
        elif (tokens[1] == "OR"):
            r = x | y
        elif (tokens[1] == "LSHIFT"):
            r = x << y
        elif (tokens[1] == "RSHIFT"):
            r = x >> y
    value[s] = str(r)
    return r

f = open(sys.argv[1])
for line in f.readlines():
    left, right = map(str.strip, line.split(" -> "))
    value[right] = left

print value
    
print eval("a")
