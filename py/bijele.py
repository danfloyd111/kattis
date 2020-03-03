import sys

standard_ls = [1, 1, 2, 2, 2, 8]

line = sys.stdin.readline()
custom_ls = map(lambda c: -int(c), line.split())
print(' '.join([str(sum(x)) for x in zip(standard_ls, custom_ls)]))
