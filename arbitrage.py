import sys

n_entries = int(sys.stdin.readline())

while n_entries != 0:
    
    while n_entries:
        
        line = sys.stdin.readline()
        curr1, curr2, change = line.split()
        units1, units2 = change.split(':')
        print(curr1,curr2,units1,units2)

        n_entries -= 1
    
    n_entries = int(sys.stdin.readline())
