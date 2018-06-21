import sys

# translate a list of strings to a list of integers
def get_values(ls):
    return list(map(lambda x: int(x), ls))

# avg of a list of values
def avg(ls):
    if len(ls) == 0:
        return None
    return sum(ls) / len(ls)

t = int(sys.stdin.readline())

for i in range(t):

    sys.stdin.readline() # empty line before test case
    
    tokens = sys.stdin.readline().split() # actually useless input
    
    n_s = 0 # number of students to transfer

    cs_values = sorted(get_values(sys.stdin.readline().split()), reverse=True)
    e_values = get_values(sys.stdin.readline().split()) # don't mind to sort values of economics students

    # actually sums of weights are the averages
    cs_avg = avg(cs_values)  
    e_avg = avg(e_values)

    while ( avg(cs_values) <= cs_avg and avg(e_values) <= e_avg ):
        e_values.append(cs_values.pop()) # move a student from computer science to economics
        n_s += 1

    print(n_s)