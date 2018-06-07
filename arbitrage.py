import sys

while True:

    n_curr = int(sys.stdin.readline())
    if n_curr == 0:
        break

    curr_list = sys.stdin.readline().split()
    n_entries = int(sys.stdin.readline())
    exchange_list = []

    while n_entries:

        line = sys.stdin.readline()
        curr1, curr2, change = line.split()
        units1, units2 = change.split(':')
        exchange_list.append({ curr1: int(units1), curr2: int(units2) })
        n_entries -= 1

    for curr in curr_list:

        


    print("currency list",curr_list)
    print("exchange list",exchange_list)
