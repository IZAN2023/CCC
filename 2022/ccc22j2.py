N = int(input())
points = []
fouls = []

for x in range(N):
    points.append(int(input()))
    fouls.append(int(input()))
# print(points, fouls)

gold_team = True
count = 0
for i in range(N):
    star = points[i] * 5 - fouls[i] * 3
    if star > 40:
        count += 1
    else:
        gold_team = False

if gold_team:
    print(f"{count}+")
else:
    print(count)