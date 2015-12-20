import md5
import sys

zeros = int(sys.argv[1]) * '0'

s = 'yzbqklnj'
i = 0
while not md5.md5(s+str(i)).hexdigest().startswith(zeros):
    i += 1

print i
