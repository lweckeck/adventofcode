import sys

def has_repeat(w):
    for i in range(len(w) - 3):
        for j in range(i+2, len(w)-1):
            if w[i:i+2] == w[j:j+2]:
                return True
    return False

def has_disrupted_repeat(w):
    for i in range(len(w) - 2):
        if w[i] == w[i+2]:
            return True
    return False

def main():
    f = open(sys.argv[1])
    count = 0
    
    for w in f.readlines():
        if has_repeat(w) and has_disrupted_repeat(w):
            count += 1
    print count

if __name__ == '__main__':
    main()
