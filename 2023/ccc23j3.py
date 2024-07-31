n = int(input())
my_sum = [0, 0, 0, 0, 0]
for i in range(n):
    my_str = input()
    for j in range(5):
        if my_str[j] == "Y":
            my_sum[j] += 1
my_max = max(my_sum)
print(my_max)
print(my_sum)
position = [i+1 for i, x in enumerate(my_sum) if x == my_max]

# for k in range(len(position)):
#     print(position[k], end="")
#     if k != len(position) -1:
#         print(',', end="")

print(",".join(map(str, position)))
