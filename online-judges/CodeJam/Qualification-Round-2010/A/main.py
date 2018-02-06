import sys

lines = sys.stdin.readlines()

for caso in range(1, len(lines)):
    [n, k] = map(int, lines[ caso ].split(' '))
    m = ((2**n) - 1)

    ans = 'OFF'
    if (k and m) == m:
        ans = 'ON'
    
    print('Case #' + str(caso) + ': ' + ans)