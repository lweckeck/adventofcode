import sys

pw = ""

def valid():
    increasing = False
    pair = '#'
    pairs = 0
    for i in reversed(range(len(pw))):
        if pw[i] == 'i' or pw[i] == 'o' or pw[i] == 'l':
            return False
        if pairs < 2 and i > 0 and pw[i] != pair and pw[i] == pw[i-1]:
            pair = pw[i]
            pairs += 1
        if not increasing and i > 1:
            if ord(pw[i]) == ord(pw[i-1]) + 1 and ord(pw[i-1]) == ord(pw[i-2]) + 1:
                increasing = True
    return increasing and pairs >= 2

def incpw():
    global pw
    for i in reversed(range(len(pw))):
        x = ord(pw[i])
        if x >= ord('z'):
            pw = pw[:i] + 'a' + pw[i+1:]
        else:
            pw = pw[:i] + chr(x+1) + pw[i+1:]
            return


def find_nextpw():
    global pw
    pw = sys.argv[1]

    incpw()
    while not valid():
        incpw()
    print pw


if __name__ == "__main__":
    find_nextpw()
