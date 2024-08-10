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




# n = int(input())
# point = [] 
# fouls = []
# total = []
# score = 0
# for i in range(n):
#     point.append(int(input()))
#     fouls.append(int(input()))
# for j in range(n):
#     total.append(point[j] * 5 - fouls[j] * 3)
#     if total[j] > 40:
#         score += 1
# if score == n:
#     print(f"{score}+")
# else:
#     print(score)
