N = int(input())

min_x = float('inf')
min_y = float('inf')
max_x = float('-inf')
max_y = float('-inf')

for _ in range(N):
    x, y = map(int, input().split(','))
    if x < min_x:
        min_x = x
    if y < min_y:
        min_y = y
    if x > max_x:
        max_x = x
    if y > max_y:
        max_y = y

print(f"{min_x-1},{min_y-1}")
print(f"{max_x+1},{max_y+1}")
