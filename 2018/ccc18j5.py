n = int(input())
my_dic = {}
for i in range(1, n + 1):
    line = input().split()
    my_dic[str(i)] = line[1:]


queue = []
visited = set()
distance = {}
for i in range(1, n + 1):
    distance[str(i)] = float('inf')

start = "1"
queue.append(start)
distance[start] = 0

while queue:
    point = queue.pop(0) 
    if point in visited:
        continue
    visited.add(point)
    for near in my_dic.get(point, []):
        if distance[near] > distance[point] + 1:
            distance[near] = distance[point] + 1
            queue.append(near)

if len(visited) == n:
    print("Y")
else:
    print("N")

min_cost = float('inf')
for point, cost in distance.items():
    if not my_dic.get(point) and min_cost > cost:
        min_cost = cost

print(min_cost + 1)

