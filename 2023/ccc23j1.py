delivered = int(input())
collisions = int(input())
if delivered > collisions:
    score = 500 + delivered * 50 - collisions * 10
else:
    score = delivered * 50 - collisions * 10
print(score)