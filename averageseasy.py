import sys

# translate a list of strings to a list of integers
def get_values(ls):
    return list(map(lambda x: int(x), ls))

t = int(sys.stdin.readline())

for i in range(t):

    sys.stdin.readline() # empty line before test case
    
    tokens = sys.stdin.readline().split() # actually useless input
    n_cs = int(tokens[0])
    n_e = int(tokens[1])

    n_s = 0 # number of students to transfer

    cs_values = sorted(get_values(sys.stdin.readline().split()), reverse=True)
    e_values = get_values(sys.stdin.readline().split()) # don't mind to sort values of economics students

    cs_tot = sum(cs_values)
    e_tot = sum(e_values)
    cs_avg = cs_tot / n_cs  
    e_avg = e_tot / n_e

    h = 0

    if (e_avg < cs_avg):
        while (h < n_cs):
            # test every computer science student
            temp_cs_avg = (cs_tot - cs_values[h]) / (n_cs - 1)
            temp_e_avg = (e_tot + cs_values[h]) / (n_e + 1)
            if (temp_cs_avg > cs_avg and temp_e_avg > e_avg):
                n_s += 1
            h += 1 

    print(n_s)