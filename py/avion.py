import sys

result = ''

for index, code in enumerate(sys.stdin, start=1):
    if 'FBI' in code:
        result += str(index) + ' '


print(result.strip() if result != '' else 'HE GOT AWAY!')
