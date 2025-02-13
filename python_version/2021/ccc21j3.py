my_list = []
while True:
    my_list.append(int(input()))
    if my_list[-1] != 99999:
        a = my_list[-1]
        if (a // 10000 + a % 100 // 1000) % 2 == 0:
            my_num = a % 10000 % 1000
            print(f"left {my_num}")
        else:
            my_num = a % 10000 % 1000
            print(f"right {my_num}")
    else:
        break

#     my_list = []
# while True:
#     k = input()
#     if k == "99999":
#         break
#     last3 = k[-3:]

#     if int(k[1]) % 2 == 1:
#         my_list.append(int(k[1]))
#         print(f"left {last3}")
#     elif int(k[1]) % 2 == 0 and k[0] != "0":
#         my_list.append(int(k[1]))
#         print(f"right {last3}")
#     elif int(k[1]) == 0 and k[0] == "0" and my_list:
#         last_value = my_list[-1]
#         if last_value % 2 == 1:
#             my_list.append(last_value)
#             print(f"left {last3}")
#         elif last_value % 2 == 0:
#             my_list.append(last_value)
#             print(f"right {last3}")

