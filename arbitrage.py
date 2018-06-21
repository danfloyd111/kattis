import sys

while True:

    n_curr = int(sys.stdin.readline())
    if n_curr == 0:
        break

    # reading first two lines
    curr_list = sys.stdin.readline().split()
    n_entries = int(sys.stdin.readline())
    matrix = []
    for i in range(n_curr):
        matrix.append([])
        for j in range(n_curr):
            if (i==j):
                matrix[i].append(1)
            else:
                matrix[i].append(0)

    # reading and storing the exchange entries
    while n_entries:

        line = sys.stdin.readline()
        curr1, curr2, change = line.split()
        units1, units2 = change.split(':')
        ratio = int(units2) / int(units1)
        index1 = curr_list.index(curr1)
        index2 = curr_list.index(curr2)
        matrix[index1][index2] = max(matrix[index1][index2], ratio)
        n_entries -= 1

    arbitrage = False

    # check for arbitrage
    for x in range(n_curr):
        for y in range(n_curr):
            for z in range(n_curr):
                matrix[y][z] = max(matrix[y][z], matrix[y][x]*matrix[x][z])

    for k in range(n_curr):
        if (matrix[k][k] > 1.0):
            arbitrage = True
            break

    if arbitrage:
        print ("Arbitrage")
    else:
        print("Ok")
