import sys
import json

def sumjson(x):
    if isinstance(x, int):
        return x
    elif isinstance(x, list):
        return sum(sumjson(elem) for elem in x)
    elif isinstance(x, dict):
        if "red" in x.values():
            return 0
        else:
            return sum(sumjson(x[key]) for key in x)
    else:
        return 0

def main():
    with open(sys.argv[1], "r") as f:
        s = json.load(f)
        print sumjson(s)

if __name__ == "__main__":
    main()
