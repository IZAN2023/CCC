same_constraints = []
diff_constraints = []
groups = []

x = int(input())
for i in range(x):
    same_constraints.append(input().split())

y = int(input())
for i in range(y):
    diff_constraints.append(input().split())

g = int(input())
for i in range(g):
    groups.append(input().split())

violation = 0

for a, b in same_constraints:
    for group in groups:
        if (a in group and b not in group) or  (a not in group and b in group) :
            violation += 1
            break
        
for a, b in diff_constraints:
    for group in groups:
        if (a in group and b in group):
            violation += 1
            break

print(violation)

