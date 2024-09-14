wtotal = 0
for i in range(6):
    wl = input()
    if wl == "W":
        wtotal += 1
if wtotal <= 2:
    print("3")
elif 3 <= wtotal <= 4:
    print("2")
elif 5 <= wtotal <= 6:
    print("1")