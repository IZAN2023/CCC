x1 = map(int, input().split())
x2= map(int, input().split())
y1 = map(int, input().split())
y2 = map(int, input().split())
q = [(x1, y1)]
directions = [(1, 2), (2, 1), (-1, 2), (2, -1), (1, -2), (-2, 1), (-1, -2), (-2, -1)]
distance = []
for _ in range(9):
    row = [float('inf')] * 9#float 表示无穷大
    distance.append(row)
distance[x1][y1] = 0
visited = [[False] * 9 for _ in range(9)]
while q:
    x, y = q.pop(0)
    if (x, y) == (x2, y2):
        print(distance[x][y])
        break
    if visited[x][y]:
        continue
    visited[x][y] = True
    
    for dx, dy in directions:
        new_x, new_y = x + dx, y + dy
        if 1 <= new_x <= 8 and 1 <= new_y <= 8 and not visited[new_x][new_y]:
            q.append((new_x, new_y))
            distance[new_x][new_y] = distance[x][y] + 1



