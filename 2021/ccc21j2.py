my_dic = {}
n = int(input())
for i in range(n):
    name = input()
    won = int(input())
    my_dic[name] =  won

my_value= my_dic.values()
my_max = max(my_value)
for item in my_dic.items():
    if item[1] == my_max:
        print(item[0])
        break