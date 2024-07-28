same_constraints = []
diff_constraints = []
# use dictionary to store student group mapping
groups_info = {}

x = int(input())
for i in range(x):
    same_constraints.append(input().split())

y = int(input())
for i in range(y):
    diff_constraints.append(input().split())

g = int(input())
for i in range(g):
    group = input().split()         # ["student1", "student2", "student3"]
    for student in group:
        groups_info[student] = i    # {"student1": 0, "student2": 0, "student3": 0}

violation = 0

for a, b in same_constraints:
    # use dictionary get method instead of for loop to improve performance
    if groups_info.get(a) != groups_info.get(b):
        violation += 1
        
for a, b in diff_constraints:
    if groups_info.get(a) == groups_info.get(b):
        violation += 1

print(violation)

