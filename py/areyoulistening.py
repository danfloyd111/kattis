import sys
import math

cx, cy, n = map(int, sys.stdin.readline().strip().split(' '))
ds = []

for i in range(n):
    x, y, r = map(int, sys.stdin.readline().strip().split(' '))
    d = math.sqrt((cx - x)**2 + (cy - y)**2) - r
    ds.append(d)

ds.sort()
print(int(ds[2]) if int(ds[2]) >= 0 else 0)

# there are at least 3 elements
# if third distance is negative, all first three distances are negative because they are sorted
# so if we have three negative distances we are inside three circular areas so we are spoiled -> print 0
