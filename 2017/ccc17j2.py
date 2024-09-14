N = int(input())
k = int(input())
total_sum = 0 
current_number = N 

for i in range(k):
    total_sum += current_number
    current_number = current_number * 10 + N 

print(total_sum)
