P = int(input())
N = int(input()) 
R = int(input()) 
now_infected = N
total_infected = N
days = 0

while total_infected <= P:
    days += 1
    now_infected *= R
    total_infected += now_infected

print(days)