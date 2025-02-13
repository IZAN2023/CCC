n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

rotated90 = [[0] * n for _ in range(n)]

orientation = False
while not orientation:
    orientation = True

    for i in range(n):
            for j in range(n):
                if (i > 0 and grid[i][j] < grid[i-1][j]) or (j > 0 and grid[i][j] < grid[i][j-1]):
                    orientation = False
                    break
            if not orientation:
                break

    if not orientation:
        for i in range(n):
            for j in range(n):
                rotated90[j][n-1-i] = grid[i][j]
        grid = [row[:] for row in rotated90]

for row in grid:
    print(' '.join(map(str, row)))