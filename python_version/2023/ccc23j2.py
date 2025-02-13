n = int(input())
my_dic = {
    "Poblano": 1500,
    "Mirasol": 6000,
    "Serrano": 15500,
    "Cayenne": 40000,
    "Thai": 75000,
    "Habanero": 125000
}
total = 0
for i in range(n):
    my_key = input()
    if my_key in list(my_dic.keys()):
        total += my_dic.get(my_key)
print(total)

# print(list(my_dic.keys()))

# print(my_dic.values())

# print(my_dic.items())
