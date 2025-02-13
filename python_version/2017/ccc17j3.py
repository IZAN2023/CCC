x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
T = int(input())

D = abs(x2 - x1) + abs(y2 - y1)

if T >= D and (T - D) % 2 == 0:
    print('Y')
else:
    print('N')
