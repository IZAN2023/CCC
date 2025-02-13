my_time = input().split(":")
passr = 120
my_time = list(map(int,my_time))

while passr > 0:
    if 7 <= my_time[0] < 10 or 15 <= my_time[0] < 19:
        passr -= 0.5
    else:
        passr -= 1
    my_time[1] += 1
    if my_time[1] == 60:
        my_time[0] += 1
        my_time[1] = 0
        if my_time[0] == 24:
            my_time[0] = 0

if my_time[0] < 10:
    my_time[0] = "0" + str(my_time[0])
if my_time[1] < 10:
    my_time[1] = "0" + str(my_time[1])

print(f"{my_time[0]}:{my_time[1]}")