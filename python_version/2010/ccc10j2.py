a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())
nikky_position = 0
byron_position = 0
step = 0
while step < s:
    if step % (a + b) < a:
        nikky_position += 1
    else:
        nikky_position -= 1

    if step % (c + d) < c:
        byron_position += 1
    else:
        byron_position -= 1
    
    step += 1
if nikky_position > byron_position:
    print("Nikky")
elif byron_position > nikky_position:
    print("Byron")
else:
    print("Tied")
    