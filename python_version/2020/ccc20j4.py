my_text = input().strip()
my_input = input().strip()

found = False
for i in range(len(my_input)):
    shifted_input = my_input[i:] + my_input[:i]#this is something like transfering ABCDE to CDEAB
    if shifted_input in my_text:
        found = True
        break

if found:
    print("yes")
else:
    print("no")