import sys


def parse_aunts(lines):
    aunts = dict()
    for line in lines:
        i = line.find(':')
        number = line[4:i]

        properties = {key.strip(): int(value) for (key, value) in
                      [p.split(':') for p in line[i+1:].split(',')]}

        aunts[number] = properties

    return aunts


def parse_tape(lines):
    tape = dict()
    for line in lines:
        key, value = line.split(':')
        tape[key] = int(value)
    return tape


def main():
    tape_file = open(sys.argv[1], 'r')
    tape = parse_tape(tape_file.readlines())

    aunt_file = open(sys.argv[2], 'r')
    aunts = parse_aunts(aunt_file.readlines())

    for (tkey, tval) in tape.items():
        for (akey, aprops) in aunts.items():
            if tkey in aprops and aprops[tkey] != tval:
                aunts.pop(akey)

    print aunts.keys()


if __name__ == "__main__":
    main()
