import sys

n = 8
limits = [19, 17, 13, 11, 7, 5, 3, 2]
values = list(map(lambda x: int(x),reversed(sys.stdin.readline().split())))

cycles = 0

for i in range(n):
    k = limits[i] - values[i] - 1
    j = i + 1
    while (j<n):
        k = k * limits[j]
        j += 1
    cycles = cycles + k

print(cycles)