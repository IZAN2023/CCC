n = int(input())
def count_ways(n):
    count = 0
    for i in range(1, 6): 
        j = n - i  
        if j >= 0 and j <= i: 
            count += 1
    return count

print(count_ways(n)) 