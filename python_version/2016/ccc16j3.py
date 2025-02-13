my_input = input()
max_length = 1

n = len(my_input)

for i in range(n):
    l, r = i, i
    while l >= 0 and r < n and my_input[l] == my_input[r]:
        current_length = r - l + 1
        if current_length > max_length:
            max_length = current_length
        l -= 1
        r += 1

    l, r = i, i + 1
    while l >= 0 and r < n and my_input[l] == my_input[r]:
        current_length = r - l + 1
        if current_length > max_length:
            max_length = current_length
        l -= 1
        r += 1
print(max_length)
