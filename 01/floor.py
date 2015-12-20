s = open('input').read()

count = 0
for c in s:
    if c is "(":
        count += 1
    elif c is ")":
        count -= 1

print count
