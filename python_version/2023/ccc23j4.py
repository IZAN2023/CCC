n = int(input())
my_list = list(map(int, input().split()))
my_list2 = list(map(int, input().split()))

total = 0

for i in range(n):
    if my_list[i] == 1:
        total += 3
        if i < n - 1 and my_list[i + 1] == 1:
            total -= 2

for j in range(n):
    if my_list2[j] == 1:
        total += 3
        if j < n - 1 and my_list2[j + 1] == 1:
            total -= 2
        if my_list[j] == 1:
            total -= 2

for k in range(n):
    l = k -1 
    if my_list[k] == my_list2[k] == my_list2[l] == 1:
        total += 2

for m in range(n):
    s = m-1
    if my_list2[m] == my_list[m] == my_list[s] == 1:
        total += 2

print(total)

