# Generate the yard
N = int(input())
yard = [[0 for _ in range(N)] for _ in range(N)]

# Change the number from 0 to 7 where there are trees
T = int(input())
for tree in range(T):
    x, y = input().split()
    yard[int(x) - 1][int(y) - 1] = 7

from pprint import pprint    # for test only
pprint(yard)                 # for test only

# Define a function to test the largest square with (x, y) as the upper left vertex and return the size
def test_max_square_pool(x, y) -> int:
    size = 1
    qualified = True
    while qualified:
        if x + size <= N and y + size <= N:
            for i in range(size):
                for j in range(size):
                    if yard[x + i][y + j] == 7:
                        print(f"Start from {x, y}, size= {size}, hits the tree: {x + i + 1, y + j + 1}")
                        qualified = False
        else:
            qualified = False
        size += 1
    return size - 2

# print(test_max_square_pool(0, 0))

# Traverse each space in the yard and test the size of the square.
# If it is larger, modify the record
max_size = 0
for i in range(N):
    for j in range(N):
       current_size = test_max_square_pool(i, j)
       if current_size > max_size:
           max_size = current_size

print(max_size)