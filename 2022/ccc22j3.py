letters = "ABCDEFGHIJKLMNOPQRST"

x = input()
is_number = False
for i in x:
    if is_number and i in letters:
        print()
        is_number = False
    if i in letters:
        print(i, end="")
    elif i == "+":
        print(" tighten ", end="")
    elif i == "-":
        print(" loosen ", end="")
    else:
        print(i, end="")
        is_number = True
