import sys


def parse_input(lines):
    molecule = lines[len(lines) - 1].strip()

    grammar = list()
    for line in lines[:len(lines) - 2]:
        left, right = line.split(" => ")
        grammar.append((left, right.strip()))
    return molecule, grammar


def tokenize(word):
    word = word.strip()
    tokens = list()
    acc = word[0]
    for c in word[1:]:
        if c.isupper():
            tokens.append(acc)
            acc = c
        else:
            acc += c
    tokens.append(acc)
    return tokens


def main():
    lines = sys.stdin.readlines()
    molecule, replacements = parse_input(lines)

    num_syms = len(tokenize(molecule))
    num_Rn = molecule.count("Rn")
    num_Ar = molecule.count("Ar")
    num_Y = molecule.count("Y")

    print num_syms - num_Rn - num_Ar - 2*num_Y - 1


if __name__ == "__main__":
    main()
