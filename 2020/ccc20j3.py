n = int(input())
list_x = []
list_y = []
# for i in range(n):
#     x,y = map(int, input().split(","))
#     list_x.append(x)
#     list_y.append(y)
for i in range(n):
    k = input().split(",")
    list_x.append(int(k[0]))
    list_y.append(int(k[1]))
print(list_x)
print(list_y)    
print(f"{min(list_x)-1},{min(list_y)-1}")
print(f"{max(list_x)+1},{max(list_y)+1}")