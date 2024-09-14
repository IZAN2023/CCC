total_list = []
for x in range(4):
    num = input().split()
    total_list.append(int(num[0])+int(num[1])+int(num[2])+int(num[3]))
if total_list[0] == total_list[1] == total_list[2] == total_list[3]:
    print("magic")
else:
    print("no magic")