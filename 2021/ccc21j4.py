# def split(word): 
#     #Split the string into a list of individual characters
#     return [char for char in word]  
# my_str = input()
# my_sorted = sorted(my_str)
# mynew_str = split(my_str)
# total = 0
# #Traverse and compare
# for x in range(len(my_sorted)):
#     if mynew_str[x] != my_sorted[x]:#if not same
#         total = total + 1
# #if total is odd number
# if total % 2 != 0:#if yes total += 1, if not dont, because why total =7 7/2 will be 3.5 and actually we need 4
#     total += 1

# print(total // 2)
n = input()
n_sorted = sorted(n)
n_list = list(n)
total = 0
# print(n_sorted)
# print(n_list)
# print(len(n))
for x in range(len(n)):
    if n_list[x] != n_sorted[x]:
        total += 1
# print(total)

if total % 2 != 0:
    new_total = total //2 +1 
else:
    new_total = total /2 
print(new_total)
