import sys

# Takes a currency and a list of exchange ratios, if it finds an
# applicable exchange it returns a dictionary that contains the new
# currency, the ratio and the original list without the found exchange.
# If it not finds anything, returns an object that signals the error
# situation wiht None as currency, -1 as exchange ratio and the
# original exchange list
def do_change(currency, excls):

    if currency is not None and excls is not None:
        for index, exc in enumerate(excls[:]):
            if exc['from'] == currency:
                to = exc['to']
                ratio = exc['ratio']
                del excls[index]
                return { 'currency': to, 'ratio': ratio, 'list': excls }
    return { 'currency': None, 'ratio': -1, 'list': excls }


while True:

    n_curr = int(sys.stdin.readline())
    if n_curr == 0:
        break

    # reading first two lines
    curr_list = sys.stdin.readline().split()
    n_entries = int(sys.stdin.readline())
    exchange_list = []

    # reading and storing the exchange objects
    while n_entries:

        line = sys.stdin.readline()
        curr1, curr2, change = line.split()
        units1, units2 = change.split(':')
        ratio = int(units2) / int(units1)
        exchange_list.append({ 'from': curr1, 'to': curr2, 'ratio': ratio })
        n_entries -= 1

    arbitrage = False

    # check for arbitrage
    for c in curr_list:

        first_change = do_change(c,exchange_list)
        current_ratio = first_change['ratio']
        current_curr = first_change['currency']
        current_list = exchange_list

        if current_curr is None:
            # no exchange is possible with actual currency, go on with next
            continue

        while current_curr != c:

            change = do_change(current_curr, current_list)
            current_ratio *= change['ratio']
            current_curr = change['currency']
            current_list = change['list']

            if current_curr is None:
                # no exchange is possible with actual currency, go on with next
                break

        if current_ratio != 1 and current_curr is not None:
            arbitrage = True
            break

    if arbitrage:
        print ("Arbitrage")
    else:
        print("Ok")
