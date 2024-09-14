H, M = map(int, input().split(':'))
D = int(input())

start_m = H * 60 + M

favourite_count = 0

for minutes in range(start_m, start_m + D):
    now_h = (minutes // 60) % 24
    now_m = minutes % 60

    H1 = now_h // 10
    H2 = now_h % 10
    M1 = now_m // 10
    M2 = now_m % 10

    if (M1 - H2) == (M2 - M1):
        favourite_count += 1

print(favourite_count)