import sys

name = sys.stdin.readline()
name = name[0:len(name)-1]  # removing new-line

last_char = ''
short_name = ''

for char in name:
    if char != last_char:
        short_name += char
    last_char = char

print(short_name)
