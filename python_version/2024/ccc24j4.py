str_1 = input()
str_2 = input()
diff_1 = list(set([char for char in str_1 if char not in str_2]))
diff_2 = list(set([char for char in str_2 if char not in str_1]))
silly_key = ""
quiet_key = "-"
wrong_key = diff_2[0]
if len(str_1) == len(str_2):
    silly_key = diff_1[0]
else:
    silly_key = diff_1[0]
    quiet_key = diff_1[1]
    new_str = ""
    for x in str_1:
        if x == silly_key:
            x = wrong_key
        elif x == quiet_key:
            x = ""
        new_str += x
    if new_str != str_2:
        silly_key = diff_1[1]
        quiet_key = diff_1[0]
print(silly_key, wrong_key)
print(quiet_key)
