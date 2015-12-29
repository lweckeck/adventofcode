import sys


def parse_input(lines):
    molecule = lines[len(lines) - 1].strip()

    replacements = dict()
    for line in lines[:len(lines) - 2]:
        source, target = line.split(" => ")
        if source in replacements:
            replacements[source].append(target.strip())
        else:
            replacements[source] = [target.strip()]
    return molecule, replacements


def onestep(molecule, replacements):
    molecules = set()
    for source in replacements:
        index = molecule.find(source)
        while (index != -1):
            for target in replacements[source]:
                molecules.add(
                    molecule[0:index] + target + molecule[index+len(source):])
            index = molecule.find(source, index+1)
    return molecules


def main():
    lines = sys.stdin.readlines()
    molecule, replacements = parse_input(lines)

    print len(onestep(molecule, replacements))


if __name__ == "__main__":
    main()
