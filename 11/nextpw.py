import sys

forbidden = {'i', 'l', 'o'}

def valid(s):
    increasing = False
    pairs = set()
    for i in range(len(s)):
        if s[i] in forbidden:
            return False
        if i < len(s) - 1 and s[i] == s[i+1]:
            pairs.add(s[i])
        if not increasing and i < len(s) - 3:
            if ord(s[i]) + 1 == ord(s[i+1]) and ord(s[i+1]) + 1 == ord(s[i+2]):
                increasing = True
    return increasing and len(pairs) >= 2

def incpw(pw):
    newpw = pw
    for i in reversed(range(len(pw))):
        x = ord(pw[i])
        if x >= ord('z'):
            newpw = newpw[:i] + 'a' + newpw[i+1:]
        else:
            return newpw[:i] + chr(x+1) + newpw[i+1:]


def find_nextpw(pw):
    pw = sys.argv[1]

    nextpw = incpw(pw)
    while not valid(nextpw):
        nextpw = incpw(nextpw)
    print nextpw


if __name__ == "__main__":
    find_nextpw(sys.argv[1])
