def split(word): 
    #Split the string into a list of individual characters
    return [char for char in word]  
my_str = input()
my_sorted = sorted(my_str)
mynew_str = split(my_str)
total = 0
#Traverse and compare
for x in range(len(my_sorted)):
    if mynew_str[x] != my_sorted[x]:#if not same
        total = total + 1
#if total is odd number
if total % 2 != 0:#if yes total += 1, if not dont, because why total =7 7/2 will be 3.5 and actually we need 4
    total += 1

print(total // 2)