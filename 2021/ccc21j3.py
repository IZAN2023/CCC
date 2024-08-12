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
