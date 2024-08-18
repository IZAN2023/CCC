a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())

my_total1 = a * 3 + b * 2 + c
my_total2 = d * 3 + e * 2 + f
if my_total1 == my_total2:
    print("T")
elif my_total1 > my_total2:
    print("A")
else:
    print("B")