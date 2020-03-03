import sys

cases = int(sys.stdin.readline())

for i in range(cases):

    categories = int(sys.stdin.readline())
    store = {}

    for j in range(categories):

        cat = sys.stdin.readline().split()[1]
        if cat in store:
            store[cat] += 1
        else:
            store[cat] = 2

    prod = 1
    for key in store.keys():
        prod *= store[key]

    print(prod - 1)
