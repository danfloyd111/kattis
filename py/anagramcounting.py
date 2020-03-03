import sys
import math

for line in sys.stdin:

    char_map = {}
    line = line[0:len(line)-1]  # removing new-line

    for char in line:
        if char in char_map:
            char_map[char] += 1
        else:
            char_map[char] = 1

    result = math.factorial(len(line))
    for key, val in char_map.items():
        result //= math.factorial(val)

    print(result)
