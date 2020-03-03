import sys
from math import factorial


def binomial(n, k):
    return factorial(n) / (factorial(n - k) * factorial(k))


n = int(sys.stdin.readline())
result = 0

if (n != 0 and n != 1):
    i = 2
    while (i < n):
        result += binomial(n, i)
        i += 1
    result += 1

print(int(result))
