N = int(input())
my_list = []
for i in range(N):
    my_list.append(int(input()))
my_set = set(my_list)
sorted_list = sorted(my_set)
third_one = sorted_list[-3]
print(third_one, my_list.count(third_one))